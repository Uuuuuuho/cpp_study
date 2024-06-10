#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable> 
#include <queue>
using namespace std::literals;

int value = 0;

std::queue<int> Q;

std::mutex m;  
std::condition_variable cv;

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> g(m);

        cv.wait(g, []() { return !Q.empty(); }); // Q가 비어 있다면 신호 대기
                                                 // Q가 비어 있지 않으면 대기안함

        int ret = Q.front();
        Q.pop();
        std::cout << "consume : " << ret
            << ", Q size : " << Q.size() << std::endl;
    }
}

void producer()
{
    while (true)
    {
        {
            std::lock_guard<std::mutex> g(m);
            Q.push(++value);
            std::cout << "produce : " << value << std::endl;
        }
        cv.notify_one();
    }
}
// 위 코드는 "data_ready" 가 필요 없습니다.
// => Q.empty()로 조사할수 있으므로.

// 위 코드의 남은 문제점은 "Q가 가득찬 경우" 입니다.
// => Q의 size 가 100000 이상이면 생산자를 대기 하는 코드를 만들어 보세요

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}