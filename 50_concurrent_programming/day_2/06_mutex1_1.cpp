#include <iostream>
#include <thread>
#include <chrono>
#include <string_view>
#include <mutex>
using namespace std::literals;

// 45 page

void delay() { std::this_thread::sleep_for(20ms); }

std::mutex m;
void foo(std::string_view name)
{
    static int x = 0;

    for (int i = 0; i < 10; i++)
    {
        // 1. 먼저 도착한 스레드는 m.lock()을 통과
        // 2. 늦게 도착한 스레드는 mutex를 소유한 스레드가 m.unlock() 할때까지 대기
        m.lock();
        x = 100;   delay();
        x = x + 1; delay();
        std::cout << name << " : " << x << std::endl; delay();
        m.unlock();
    }
}

int main()
{
    std::thread t1(foo, "A");
    std::thread t2(foo, "\tB");
    t1.join();
    t2.join();
}



