#include <iostream>
#include <thread>
#include <mutex>
#include "chronometry.h"

constexpr unsigned int cnt = 1000000;


long x = 0; // 모든 스레드가 공유.

/*
void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
//      x = x + 1;  
        // 위 한줄의 어셈블리 코드는 아래 코드 입니다.
        // "x64" 말고 "x86" 으로 설정하시면 실행해 볼수 있습니다.
        // => 아래 코드를 3개의 스레드가 동시에 실행하므로 "안전하게 1증가"는 안됩니다.
        __asm
        {
            mov eax, x
            add eax, 1
            mov x,   eax
        }
    }
}
*/

// 해결책 1. mutex 로 동기화 하자.
// std::mutex m;

// void foo()
// {
//     for (int i = 0; i < 1000000; ++i)
//     {
//         std::lock_guard<std::mutex> g(m);
//         x = x + 1;  
//     }
// }


// 해결책 2. CPU 가 제공하는 멀티스레드(멀티 코어)에 안전한 OPCODE(CPU 명령)사용
// => 0.0422231
/*
void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
        // lock 접두어 : CPU core 가 여러개 있더라도
        //              1개의 core가 x 변수를 사용하는 동안에 다른 core(스레드)는
        //              접근할수 없도록 해달라
        //              => CPU 마다 명령은 다를수 있습니다.(아래코드는 intel호환)
        __asm
        {
            lock inc x
        }
        // 위와 같은 개념을 "lock-free" 라고 합니다.
        // 1. lock 자체가 없는 것이 아니라..
        // 2. OS 의 동기화 도구를 사용하지 않고
        //    CPU 레벨의 명령의 사용해서 동기화 한다는 것
    }
}
*/

// 해결책 3. C++ 표준의 std::atomic 사용
#include <atomic>

std::atomic<long> x = 0;    // x는 long이 아닌 std::atomic입니다.
                            // ++,==,!= 등의 대부분 연산자가 재정의되어 있습니다.

void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
        ++x;    // 1. x.operator++() 호출됩니다. 아래 코드와 동일합니다.
        x.fetch_add(1); // 2. 위와 동일합니다.
                
        int n1 = x;
        int n2 = x.load();  // 위와 동일

        // 연산자 재정의와 멤버함수 호출의 차이점.
        x.fetch_add(1);
        x.fetch_add(1, std::memory_order_relaxed);  // 2번째 인자 변경 가능
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