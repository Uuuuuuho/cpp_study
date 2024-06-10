#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

// 아래 코드는 "생산자/소비자"간의 공유 자원의 동시 접근은 할수 없도록 mutex를 사용합니다.
// 하지만, "생산후 소비"를 할수 있도록 되어 있지는 않습니다.

std::mutex m;
int shared_data = 0;

void consumer()
{
    std::lock_guard<std::mutex> lg(m);
    std::cout << "consume : " << shared_data << std::endl;
}
void producer()
{
    std::this_thread::sleep_for(10ms);
    std::lock_guard<std::mutex> lg(m);
    shared_data = 100;
    std::cout << "produce : " << shared_data << std::endl;
}
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}