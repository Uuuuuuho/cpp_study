#include <iostream>
#include <thread>

// ������ �Լ��� ���

// 1. foo�� �Ϲ� �Լ�
void foo(int a, double d) {}

// 2. Run�� ��� �Լ�
struct Machine
{
    void Run(int a, double d) {}
};

// 3. �Լ� ��ü - () ������ �����ǵ� Ŭ����
struct Work
{
    void operator()(int a, double b) const {}
};

struct FUNC
{
    int& value;
    FUNC(int& r) : value(r) {}

    void operator()() const
    {
        value = 10;
    }
};

int main()
{
    // 1. �Ϲ��Լ��� ������� ����
    std::thread t1(&foo, 3, 3.4);

    // 2. ����Լ��� ������� ����
    Machine m;
    std::thread t2(&Machine::Run, &m, 10, 3.4); // m.Run(10, 3.4)�� ������� ����.

    // 3. �Լ���ü
    Work w;
    // w(3, 3.4); // ��ü���� �Լ�ó�� ��밡��. w.operator()(3,3.4)
    std::thread t3(w, 3, 3.4);
    // std::thread t3(&w, 3, 3.4); // error

    // 4. ����ǥ���� ����
    std::thread t4([]() {std::cout << "lambda" << std::endl; });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

