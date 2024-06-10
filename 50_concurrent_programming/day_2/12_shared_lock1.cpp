#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string_view>
using namespace std::literals;

// shared_mutex 동작 방식
// 
// m.lock() 을 하면 : 다른스레드의 lock(), lock_shared()는 모두 대기

// m.lock_shared() : 다른 스레드의 lock()은 대기 (Writer)
//                   다른 스레드의 lock_shared()는 대기안함(Reader)

// 결론
// Write 는 "lock"
// Read  는 "lock_shared"



//std::mutex m;

std::shared_mutex m; // C++17 부터 지원 됩니다. 

int share_data = 0;

void Writer()
{
    while (1)
    {
        {
            // lock()/unlock() 관리는 lock_guard로!!

            std::lock_guard<std::shared_mutex> g(m);

            // m.lock();
            share_data = share_data + 1;
            std::cout << "Writer : " << share_data << std::endl;
            std::this_thread::sleep_for(1s);
            // m.unlock();
        }
        std::this_thread::sleep_for(10ms);
    }
}

void Reader(std::string_view name)
{
    while (1)
    {
        {
    //      std::lock_guard<std::shared_mutex> g(m); // lock() unlock()
            std::shared_lock<std::shared_mutex> g(m);   // lock_shared()
                                                        // unlock_shared()

    //      m.lock_shared();
            std::cout << "Reader(" << name << ") : " << share_data << std::endl;
            std::this_thread::sleep_for(500ms);
    //      m.unlock_shared();
        }
        std::this_thread::sleep_for(10ms);
    }
}

int main()
{
    std::thread t1(Writer);
    std::thread t2(Reader, "A");
    std::thread t3(Reader, "B");
    std::thread t4(Reader, "C");
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}