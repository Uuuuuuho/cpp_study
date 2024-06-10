#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex       m1, m2, m3;
std::timed_mutex tm1, tm2, tm3;

/*  unique_lock은 기능이 많습니다. 
    condition variable은 unique_lock과 같이 사용해야함.
*/

int main()
{
    std::unique_lock<std::mutex> u1;                        // 아직 뮤텍스와 연결안됨
    std::unique_lock<std::mutex> u2(m1);                    // 생성자에서 m1.lock()
    std::unique_lock<std::mutex> u3(m2, std::try_to_lock);  // 생성자에서 m2.try_lock() 수행

    // u3 (unique_lock의 try_lock)의 mutex lock acquire는 아래처럼 조사함.
    if (u3.owns_lock())
        std::cout << "acquire lock" << std::endl;
    else
        std::cout << "fail to lock" << std::endl;

    // 이미 lock()이 된 mutex를 unlock()만 자동으로
    m3.lock();
    std::unique_lock<std::mutex> u4(m3, std::adopt_lock);   

    //==================================================================
    // 아직 lock() 안했는데, 미래에 lock()을 할 것이다.
    std::unique_lock<std::timed_mutex> u5(tm1, std::defer_lock);
    auto ret = u5.try_lock_for(2s);     // 이 함수를 사용하려면
                                        // u5는 반드시 timed_mutex이여야함.

    // 생성자에서 try_lcok_for(2s)
    std::unique_lock<std::timed_mutex> u6(tm2, 2s);  // tm2.try_lock_for() 사용
    std::unique_lock<std::timed_mutex> u7(tm3, std::chrono::steady_clock::now() + 2s);
    // tm3.try_lock_until() 사용

    u2.unlock(); // explicit unlock()하는 멤버 함수 제공
}
