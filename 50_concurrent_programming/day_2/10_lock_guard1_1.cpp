#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

// 54 page

std::mutex m;

void goo()
{
    std::lock_guard<std::mutex> g(m);
    /*  1. lock_guard 객체 g가 m을 "참조"로 보관
        2. 생성자에서 m.lock()을 수행함.
        핵심 : 아래 코드에서 예외가 바랭해도 지역변수 "g"는
            안전하게 파괴(소멸자호출)됨을 보장함.
            즉, 최소한 unlock()은 수행됨.
            전문용어로 "stack unwinding"이라고 함.
    */
    std::cout << "using shared data" << std::endl;

    // throw std::exception(); // 예외 발생
    /*  "throw"에서 jump하더라도 "g"의 destructor는 call하고 jump를 수행함. */
}

void hoo()
{
    // 함수 전체가 아닌 일부 구간만 mutex로 동기화하려면 블럭 {}을 사용하면 됩니다.
    {
        std::lock_guard<std::mutex> g(m);

        std::cout << "using shared data" << std::endl;
    } // <= 여기서 unlock
}

void foo()
{
    goo();
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}



