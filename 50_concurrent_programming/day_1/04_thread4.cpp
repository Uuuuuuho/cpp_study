#include <iostream>
#include <thread>
#include <chrono>
using namespace std::literals;


// 스레드 ID

// std::this_thread::get_id()  vs std::thread::get_id()멤버함수
void foo()
{
    // 자신의 스레드 ID 출력
    std::cout << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::thread t(&foo);
    
    std::this_thread::sleep_for(1s);

    // 자신의 ID 가 아닌, 자신이 생성한 스레드의 ID 구하기
    std::thread::id tid = t.get_id();
    
    std::cout << "created thread id : " << tid << std::endl;

    t.join();
}
