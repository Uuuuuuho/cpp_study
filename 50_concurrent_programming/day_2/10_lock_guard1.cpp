#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

// 54 page

// lock()/unlock()을 직접하는 경우, 예외등이 발생하면 "deadlock" 현상이 있을수 있습니다.
// => RAII 기술(생성자에서 lock, 소멸자에서 unlock) 을 관리해야 합니다.

std::mutex m;

void goo()
{
    m.lock();    
    std::cout << "using shared data" << std::endl;

    throw std::exception(); // 예외 발생

    m.unlock();
}

void foo()
{
    try
    {
        goo();
    }
    catch (...)
    {
        std::cout << "예외 발생" << std::endl;
    }
}



int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}