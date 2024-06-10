#include <iostream>
#include <thread>

// 스레드 함수의 모양

// 1. foo는 일반 함수
void foo(int a, double d) {}

// 2. Run은 멤버 함수
struct Machine
{
    void Run(int a, double d) {}
};

// 3. 함수 객체 - () 연산자 재정의된 클래스
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
    // 1. 일반함수를 스레드로 실행
    std::thread t1(&foo, 3, 3.4);

    // 2. 멤버함수를 스레드로 실행
    Machine m;
    std::thread t2(&Machine::Run, &m, 10, 3.4); // m.Run(10, 3.4)를 스레드로 실행.

    // 3. 함수객체
    Work w;
    // w(3, 3.4); // 객체지만 함수처럼 사용가능. w.operator()(3,3.4)
    std::thread t3(w, 3, 3.4);
    // std::thread t3(&w, 3, 3.4); // error

    // 4. 람다표현식 실행
    std::thread t4([]() {std::cout << "lambda" << std::endl; });

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

