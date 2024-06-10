#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// 35 page

void add(std::promise<int>& p, int a, int b)
{
    std::this_thread::sleep_for(1s);

    p.set_value(a + b);
}

int main()
{
    std::promise<int> pm;
    std::future<int> ft = pm.get_future();

    std::thread t(add, std::ref(pm), 10, 20);

//  int n1 = ft.get();  // promise객체.set_value() 할때 까지 무한이 대기..


    std::future_status ret = ft.wait_for(2s); // 특정 시간동안 대기
                                // 2초가 지나거나 set_value()가 될때까지대기

    if (ret == std::future_status::ready)
    {
        std::cout << "set_value()가 되어서 결과 준비됨" << std::endl;
        std::cout << ft.get() << std::endl;
    }
    else if (ret == std::future_status::timeout)
    {
        std::cout << "2s 경과" << std::endl;
    }
    else if (ret == std::future_status::deferred)
    {
        std::cout << "스레드 자체가 아직 실행 안됨. 지연실행 으로 한경우" << std::endl;
    }

    t.join();
}

