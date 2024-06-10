#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

// 스레드 여러개가 foo를 실행해도 "init" 은 한번만 호출되게 하려면

// 1. std::once_flag 변수를 전역으로 한개만 생성합니다.
std::once_flag flag;

void init(int a, double d)
{
    std::cout << "init" << std::endl;
    std::this_thread::sleep_for(2s);
}
void foo()
{
    std::cout << "start foo" << std::endl;

    // 2. init()를 직접 호출하지 말고, std::call_once()를 사용합니다.
    // init(10, 3.4);    
    std::call_once(flag, init, 10, 3.4);
        // 1. 제일 먼저 도착한 스레드가 init() 함수를 호출합니다.
        // 2. 이후 도착한 스레드는 init() 호출이 종료 될때까지 대기하게됩니다.
        // 3. init() 호출이 종료 되면 모든 스레드가 다음줄을 실행.. 
    std::cout << "finish foo" << std::endl;
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}




