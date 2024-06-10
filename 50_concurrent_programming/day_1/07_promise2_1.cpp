#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;


void divide(std::promise<int>& p, int a, int b)
{
    try
    {
        if (b == 0)
        {
            throw std::runtime_error("divide by zero");
        }

        p.set_value(a / b);
    }
    catch (...)
    {
        // 이제 발생된 예외를 promise 를 보내준 스레드(주스레드)에 전달합니다.
        // p.set_exception( std::current_exception() );

        // 예외전달후 스레드 종료하고자 하는 경우
        p.set_exception_at_thread_exit(std::current_exception());
    }
}

int main()
{
    std::promise<int> pm;
    std::future<int>  ft = pm.get_future();

    std::thread t(divide, std::ref(pm), 10, 0);

    try
    { 
        int ret = ft.get(); // p.set_value() 또는
                            // p.set_exception() 할때 까지 대기
    }
    catch (...)
    {
        std::cout << "exception occurred" << std::endl;
    }

    t.join();
}
