#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>
#include <semaphore>    
using namespace std::literals;

//std::counting_semaphore<3> sem(3);

std::binary_semaphore sem(1); // 최대 크기가 1인 세마 포어
                                // 자원의 독점
                                // 뮤텍스 : 소유자만 unlock 가능
                                // 이진세마포어 : 누구나 카운트 증가 가능

void Download(std::string name)
{
    sem.acquire();
    //=====================================
    for (int i = 0; i < 100; i++)
    {
        std::cout << name;
        std::this_thread::sleep_for(10ms);
    }
    std::cout << "\n finish " << name << std::endl;
    //=====================================
//  sem.release();
}

int main()
{
    std::thread t1(Download, "1");
    std::thread t2(Download, "2");
    std::thread t3(Download, "3");
    std::thread t4(Download, "4");
    std::thread t5(Download, "5");

    std::this_thread::sleep_for(1s); sem.release();
    std::this_thread::sleep_for(1s); sem.release();
    std::this_thread::sleep_for(1s); sem.release();
    std::this_thread::sleep_for(1s); sem.release();

    t1.join();    t2.join();
    t3.join();    t4.join();
    t5.join();
}