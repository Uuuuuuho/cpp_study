#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

// std::mutex m;   // 스레드가 하나의 뮤텍스를 2번이상 lock() 할 수 없다.
std::recursive_mutex m; // 뮤텍스 소유자가 동일한 mutex를 다시 lock() 할 수 있다.
                        // 단, lock() 횟수만큼 unlock()해야함.
int share_data = 0;

void foo()
{
    m.lock();
    m.lock();
    share_data = 100;
    std::cout << "using share_data" << std::endl;
    m.unlock();
    m.unlock();
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}




