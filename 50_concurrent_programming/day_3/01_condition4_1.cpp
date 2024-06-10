#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable> 
#include <queue>
using namespace std::literals;

int value = 0;

std::queue<int> Q; 

std::mutex m;   // Q의 접근 동기화를 위한 뮤텍스

// 아래 코드는 Q의 동시 접근은 해결했습니다
// 그런데, Q가 비어있을때 소비를 하게 되면 문제 입니다.
// Q size 가 0일때 소비자 스레드가 Q에서 꺼내면 죽게 됩니다.
void consumer()
{
    std::this_thread::sleep_for(500ms);  // 소비자가 늦게 출발..

    while (true)
    {
        std::lock_guard<std::mutex> g(m);

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
        std::lock_guard<std::mutex> g(m);
        Q.push(++value);
        std::cout << "produce : " << value << std::endl;
    }
}

int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}