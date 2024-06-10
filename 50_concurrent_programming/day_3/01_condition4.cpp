#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable> // 앞 소스에도 이헤더 넣어주세요
#include <queue>
using namespace std::literals;

int value = 0;

std::queue<int> Q; // STL 의 queue 는 멀티스레드 환경에서 안전하지 않습니다

// 아래 코드는 여러스레드가 Q를 접근할때 접근 동기화가 되고 있지 않습니다.

void consumer()
{
    while (true)
    {
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