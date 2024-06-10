#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>& p, int a, int b)
{
    std::this_thread::sleep_for(1s);
    p.set_value(a + b);
}

int main()
{
    std::promise<int> pm;

    // 핵심 1. promise 에서 get_future 는 한번만 가능합니다
    std::future<int> ft = pm.get_future();
//  std::future<int> ft2 = pm.get_future(); // 예외 발생.

    // 핵심 2. future는 복사 안됩니다.
//  std::future<int> ft3 = ft; // error

    std::thread t(add, std::ref(pm), 10, 20);
    

    // 핵심 3. ft.get()는 한번만 가능합니다.
    std::cout << ft.valid() << std::endl; // 1
    int ret = ft.get(); 

    std::cout << ft.valid() << std::endl; // 0
    int ret2 = ft.get(); // 예외 발생


    t.join();
}
