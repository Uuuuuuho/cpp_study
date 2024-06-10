#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::timed_mutex m;

int main()
{
    std::unique_lock<std::timed_mutex> u1;      // mutex 연결안됨
    std::unique_lock<std::timed_mutex> u2(m);   // m.lock()수행

    // u1 = u2;                // error. 복사 또는 대입은 안됨
    u1 = std::move(u2);     // ok.    move는 가능
                            // u2가 관리하던 뮤텍스를 u1이 관리
    std::cout << u1.owns_lock() << std::endl; 

    if (u1) // investigation
        std::cout << "acquire" << std::endl;

    u1.unlock();    // explicit unlock

    std::cout << u1.owns_lock() << std::endl;  

    if (u1.try_lock_for(2s))    // explicit lock again...
    {
        //....
        u1.unlock();
    }

    u1.release();   // u1과 관련된 mutex 연결 해지
}



