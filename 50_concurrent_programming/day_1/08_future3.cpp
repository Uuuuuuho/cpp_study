#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

void add(std::promise<int>&& p, int a, int b)
{
    std::this_thread::sleep_for(1s);
    p.set_value(a + b);
}
int main()
{
    std::promise<int> pm;
    std::future<int> ft = pm.get_future();

    std::shared_future<int> sft1 = ft1.share(); 
    // std::shared_future<int> sft2 = ft1.share(); // 예외. 이러게 다시 꺼내지말고,
    std::shared_future<int> sft2 = sft1;         // 복사해서 사용해야함.

    // sft1, sft2가 각각 get() 가능함.
    // std::thread t1(foo,sft1);
    // std::thread t2(goo,sft2);

    std::thread t(add, std::move(pm), 10, 20);

    // 주의 !! 주스레드도 반드시 shared_future로 대기해야함.
    // 만약 아래처러 future인 ft로 get()을 하면
    // shared_future는 더이상 get() 안됨. (예외발생)

    int ret1 = ft.get();

    t.join();
}




