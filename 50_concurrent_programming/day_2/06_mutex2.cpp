#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

std::mutex m;
int share_data = 0;

void foo()
{
    // m.lock();       // 뮤텍스를 획득하지 못하면 대기
    // m.try_lock();   // 뮤텍스를 획득하지 못하면 nonblocking, return false.
    if(m.try_lock()){
        // try_lock()이 true를 반환한 경우, mutex를 획득했으므로
        // 공유자원 사용후, unlock
        share_data = 100;
        m.unlock();
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(foo);

    t1.join();
    t2.join();
}



