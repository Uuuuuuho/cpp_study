#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std::literals;

void foo(std::promise<int>&& p)
{
    std::cout << "start foo" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "finish foo" << std::endl;
    p.set_value(10);
}
int main()
{
    std::promise<int> p;
    std::future<int> ft = p.get_future();

    std::thread t(foo, std::move(p));
    t.detach();
    // ft.get();
}   // 지역변수 ft(future) 파괴 => 주스레드가 죽음. foo 스레드가 print하기 전에 foo 스레드 파괴.

/*  
    주의하세요. future 객체의 get()을 호출하지 않은 경우
    1. async() 반환값으로 얻은 future : 소멸자에서 "get()" 호출해서 대기
    2. promise 객체에서   얻은 future : 소멸자에서 대기 안함.
*/



