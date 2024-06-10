#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex m;
int shared_data = 0;


std::condition_variable cv;



// 아래 코드의 문제점
// => 소비자가 늦게 도착합니다.
// => 생성자가 cv.notify_one() 할때, 소비자는 cv.wait()에 도착하기 전입니다.

void consumer()
{
    std::this_thread::sleep_for(10ms);

    std::unique_lock<std::mutex> ul(m); 

    cv.wait(ul);  // <= 이미 cv.notify_one() 한 후에
                  // <= 늦게 도착해서 wait() 하게 됩니다.
                  //    다시 cv.notify_one() 를 해주지 않게 되므로 계속대기합니다.
                  // 해결책은"2-1번소스"

    std::cout << "consume : " << shared_data << std::endl;
}

void producer()
{
    {
        std::lock_guard<std::mutex> lg(m);
        shared_data = 100;
        std::cout << "produce : " << shared_data << std::endl;
    }
    cv.notify_one();
}



int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}