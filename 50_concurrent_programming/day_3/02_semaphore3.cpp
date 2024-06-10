#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>
#include <semaphore>    
using namespace std::literals;


// 뮤텍스    : 자원의 독점,          소유자만 unlock        
// 세마포어  : 한정된 갯수로 공유,    누구가 카운트 증가 가능(소유자 없음)


std::counting_semaphore<3> sem(3);

void Download(std::string name)
{
    sem.acquire(); 
    //=====================================
    for (int i = 0; i < 100; i++)
    {
        std::cout << name;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << "\n finish " << name << std::endl;
    //=====================================
//    sem.release(); 
}


int main()
{
    std::thread t1(Download, "1");
    std::thread t2(Download, "2");
    std::thread t3(Download, "3");
    std::thread t4(Download, "4");
    std::thread t5(Download, "5");

    std::this_thread::sleep_for(3s); 
//  sem.release();  // 세마 포어 갯수 1 증가
    sem.release(2); // 2증가



    t1.join();    t2.join();
    t3.join();    t4.join();
    t5.join();
}