#include <iostream>
#include <thread>
#include <mutex>
#include "chronometry.h"

constexpr unsigned int cnt = 1000000;


long x = 0; // ��� �����尡 ����.

/*
void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
//      x = x + 1;  
        // �� ������ ����� �ڵ�� �Ʒ� �ڵ� �Դϴ�.
        // "x64" ���� "x86" ���� �����Ͻø� ������ ���� �ֽ��ϴ�.
        // => �Ʒ� �ڵ带 3���� �����尡 ���ÿ� �����ϹǷ� "�����ϰ� 1����"�� �ȵ˴ϴ�.
        __asm
        {
            mov eax, x
            add eax, 1
            mov x,   eax
        }
    }
}
*/

// �ذ�å 1. mutex �� ����ȭ ����.
// std::mutex m;

// void foo()
// {
//     for (int i = 0; i < 1000000; ++i)
//     {
//         std::lock_guard<std::mutex> g(m);
//         x = x + 1;  
//     }
// }


// �ذ�å 2. CPU �� �����ϴ� ��Ƽ������(��Ƽ �ھ�)�� ������ OPCODE(CPU ���)���
// => 0.0422231
/*
void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
        // lock ���ξ� : CPU core �� ������ �ִ���
        //              1���� core�� x ������ ����ϴ� ���ȿ� �ٸ� core(������)��
        //              �����Ҽ� ������ �ش޶�
        //              => CPU ���� ����� �ٸ��� �ֽ��ϴ�.(�Ʒ��ڵ�� intelȣȯ)
        __asm
        {
            lock inc x
        }
        // ���� ���� ������ "lock-free" ��� �մϴ�.
        // 1. lock ��ü�� ���� ���� �ƴ϶�..
        // 2. OS �� ����ȭ ������ ������� �ʰ�
        //    CPU ������ ����� ����ؼ� ����ȭ �Ѵٴ� ��
    }
}
*/

// �ذ�å 3. C++ ǥ���� std::atomic ���
#include <atomic>

std::atomic<long> x = 0;    // x�� long�� �ƴ� std::atomic�Դϴ�.
                            // ++,==,!= ���� ��κ� �����ڰ� �����ǵǾ� �ֽ��ϴ�.

void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
        ++x;    // 1. x.operator++() ȣ��˴ϴ�. �Ʒ� �ڵ�� �����մϴ�.
        x.fetch_add(1); // 2. ���� �����մϴ�.
                
        int n1 = x;
        int n2 = x.load();  // ���� ����

        // ������ �����ǿ� ����Լ� ȣ���� ������.
        x.fetch_add(1);
        x.fetch_add(1, std::memory_order_relaxed);  // 2��° ���� ���� ����
    }
}


void test()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
}

int main()
{
    test();
    std::cout << x << std::endl;
}