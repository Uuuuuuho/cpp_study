#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

//std::mutex m;   // m.lock()
                  // m.try_lock()

std::timed_mutex m; // m.try_lock_for(시간)   : 특정 시간 동안 대기
                    // m.try_lock_until(시간) : 특정 시간 까지 대기

int share_data = 0;

void foo()
{
    //m.lock();
    //if ( m.try_lock() )
    if (m.try_lock_for(2s)) // 획득을 위해 2초만 대기, 2초 지나면 false 반환
    {
        share_data = 100;
        std::cout << "using share_data" << std::endl;
        std::this_thread::sleep_for(3s);
        m.unlock();
    }
    else
    {
        std::cout << "뮤텍스 획득 실패" << std::endl;
    }
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}


// 53 page 표 수정
// C++표준 mutex 는 6개 입니다. - 53 page

// std::mutex,       std::recursive_mutex,       std::shared_mutex
// std::timed_mutex, std::recursive_timed_mutex, std::shared_timed_mutex