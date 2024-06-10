#include <iostream>
#include <thread>
#include <chrono>
#include <string_view>
#include <mutex>
using namespace std::literals;

// 45 page

void delay() { std::this_thread::sleep_for(20ms); }

void foo(std::string_view name)
{
    /*  핵심 1. 지역변수는 모든 스레드가 따로 사용
                항상 안전하다.
    */
    // int x = 0;

    /*  핵심 2. static local variable은 모든 스레드가 공유함.
                아래 코드에서 x의출력 결과를 예측할 수 없습니다.
    */
    static int x = 0;

    for (int i = 0; i < 10; i++)
    {
        x = 100;   delay();
        x = x + 1; delay();
        std::cout << name << " : " << x << std::endl; delay();
    }
}

int main()
{
    std::thread t1(foo, "A");
    std::thread t2(foo, "\tB");
    t1.join();
    t2.join();
}



