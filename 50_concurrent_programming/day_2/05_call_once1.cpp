#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

// 75 page
// 아래 코드는 스레드 별로 init 이 호출됩니다.
// 즉, 스레드 2개가 foo를 실행하므로 init이 2번 호출됩니다.
void init(int a, double d)
{
    std::cout << "init" << std::endl;
    std::this_thread::sleep_for(2s);
}
void foo()
{
    std::cout << "start foo" << std::endl;
    init(10, 3.4);    // ???
    std::cout << "finish foo" << std::endl;
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}



