#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex m;
int shared_data = 0;


std::condition_variable cv;

// 일반적으로 "condition_variable" 은 flag 변수와 함께 사용하게 됩니다
bool data_ready = false;

void consumer()
{
    std::this_thread::sleep_for(10ms);
    std::unique_lock<std::mutex> ul(m);

//  cv.wait(ul);       // 무조건 신호가 올때 까지 대기
//  cv.wait(ul, 함수);  // 함수를 먼저 실행하고, 
                       // => 함수반환값이 거짓이면 신호가 올때까지 대기
                       // => 함수반환값이 참이면 대기 안함.

    cv.wait(ul, []() { return data_ready; });
                        // => 데이타가 준비 되어 있다면 대기 하지 않고
                        //    바로 사용하겠다는 의미.

    std::cout << "consume : " << shared_data << std::endl;
}

void producer()  // 먼저 도착
{
    {
        std::lock_guard<std::mutex> lg(m);
        shared_data = 100;
        std::cout << "produce : " << shared_data << std::endl;

        data_ready = true;
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