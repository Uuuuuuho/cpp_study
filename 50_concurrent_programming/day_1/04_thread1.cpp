#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;

// 21 page

void foo()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "foo : " << i << std::endl;
        std::this_thread::sleep_for(100ms);
    }
}

int main()
{
    // foo(); // main thread가 그냥 호출

    // 핵심 1. 스레드를 생성하는 방법.
    std::thread t(&foo);    // start() 같은 함수를 호출할 필요없음.
                            // 객체 생성이 스레드 생성.
    
    // 핵심 2. 스레드 생성한 경우 반드시
    // 대기하거나, 분리해야함.
    // t.join();   // 스레드 종료 대기
                // linux : pthread_join
                // windows : WaitForSingleObject()
    
    t.detach(); // 스레드 분리

    std::cout << "main keep going..." << std::endl;
}
// 주스레드 종료시 "살아있던 모든 스레드는 강제 종료".
