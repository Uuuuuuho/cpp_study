#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void divide(std::promise<int>&& p, int a, int b)
{
    if(b==0){
        // 스레드 함수 안에서 예외를 던지면
            // 주스레드로 전달되지 않음.
            // 현재 스레드의 디폴트 핸들러(abort() 호출 후 종료됨)가 실행됨.
        throw std::runtime_error("divide by zero");
    }
    p.set_value(a / b);
}

int main()
{
    std::promise<int> pm;
    std::future<int>  ft = pm.get_future();

    try
    {
        /* code */
        std::thread t(divide, std::move(pm), 10, 0);
        int ret = ft.get(); // p.set_value() 할때까지 대기
        t.join();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    
}



