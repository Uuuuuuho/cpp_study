#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::literals;

std::mutex m;
int shared_data = 0;


std::condition_variable cv;


bool data_ready = false;    // 데이타가 준비됨.
bool data_process = false;  // 데이타를 처리했음.

void consumer()
{
    std::unique_lock<std::mutex> ul(m);

    cv.wait(ul, []() { return data_ready; });

    std::cout << "consume : " << shared_data << std::endl;

    //====================
    // data  처리를 완료 했음을 생산자 스레드에 알려준다.
    data_process = true;

    ul.unlock();        // mutex lock 을 먼저 unlock 한후에
    cv.notify_one();    // 신호를 보내세요!!

}

void producer() 
{
    {
        std::lock_guard<std::mutex> lg(m);
        shared_data = 100;
        std::cout << "produce : " << shared_data << std::endl;

        data_ready = true;
    }
    cv.notify_one();

    // data 처리가 완료 되었다고 신호가 올때 까지 대기 합니다.
    std::unique_lock<std::mutex> ul(m);

    cv.wait(ul, []() {return data_process; });

    std::cout << "생산자 메세지 : 데이타 처리 완료 신호 받음" << std::endl;
}





int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}