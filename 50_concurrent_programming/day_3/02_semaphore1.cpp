#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>
#include <semaphore>    // C++20 부터 지원됩니다.
using namespace std::literals;


std::mutex m;

// 아래 코드는 공유 자원(네트워크등) 을 한개의 스레드가 독점하는 코드입니다.
void Download(std::string name)
{
    m.lock();
    //=====================================
    for (int i = 0; i < 100; i++)
    {
        std::cout << name;
        std::this_thread::sleep_for(30ms);
    }
    std::cout << "\n finish " << name << std::endl;
    //=====================================
    m.unlock();
}


int main()
{
    std::thread t1(Download, "1");
    std::thread t2(Download, "2");
    std::thread t3(Download, "3");
    std::thread t4(Download, "4");
    std::thread t5(Download, "5");

    t1.join();    t2.join();
    t3.join();    t4.join();
    t5.join();
}