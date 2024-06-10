#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
using namespace std::literals;

std::mutex m;
int shared_data = 0;

// condition_variable을 사용하는 방법
// 1. condition variable declaration
std::condition_variable cv;

void consumer()
{
    // 2. 대기하는 스레드에서는 
    //      std::unique_lock으로 뮤텍스 획득
    // std::lock_guard<std::mutex> lg(m);
    std::unique_lock<std::mutex> ul(m);     // A. mutex를 lock
                                            // lock_guard는 파괴자에서만 unlock이 가능하기 때문에
                                            // unlock이 가능한 unique_lock을 사용해야만 함.

    cv.wait(ul);        // 다른 스레드에서 cv.notify_xxx()를 할때까지 대기
                        // B. ul.unlock()으로 lock을 풀고...
                        // C. cv가 신호를 줄때까지 대기...
                        // D. 신호가 오면 다시 ul.lock()으로 뮤텍스를 획득합니다.

    std::cout << "consume : " << shared_data << std::endl;
}
void producer()
{
    std::this_thread::sleep_for(10ms);
    {
    std::lock_guard<std::mutex> lg(m);
    shared_data = 100;
    std::cout << "produce : " << shared_data << std::endl;
    }
    // 3. 신호를 주는 스레드는 unique_lock 을 사용하지 않아도 됩니다.
    // 공유 자원이 준비 되면 cv.notify_xxx() 함수로 신호를 전달합니다.
    // 주의.. 되도록 이면 신호를 주기전에 mutex 를 unlock 하고 신호를 주세요..
    // => cv.wait()는 신호가 와서 깨어난후, 다시 mutex 의 lock 을 시도 합니다.
    
    cv.notify_one();

    std::this_thread::sleep_for(3s);    // lock_guard를 사용하기 때문에 파괴자가 불릴때까지 consumer는 기다려야함.
}
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join(); 
    t2.join();
}