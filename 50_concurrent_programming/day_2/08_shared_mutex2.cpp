#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string_view>
using namespace std::literals;

// std::mutex m;
std::shared_mutex m;    // C++17부터 지원됩니다.
int share_data = 0;

void Writer()
{
    while (1)
    {   
        // 핵심 1. 공유 자원에 write는 lock()/unlock() 
        m.lock();
        share_data = share_data + 1;
        std::cout << "Writer : " << share_data << std::endl;
        std::this_thread::sleep_for(1s);
        m.unlock();
        std::this_thread::sleep_for(10ms);
    }
}
void Reader(std::string_view name)
{
    while (1)
    {
        // 핵심 2. 공유자원을 read할때는 lock_shared()/unlock_shared() 사용
        m.lock_shared();
        std::cout << "Reader(" << name << ") : " << share_data << std::endl;
        std::this_thread::sleep_for(500ms);
        m.unlock_shared();
        std::this_thread::sleep_for(10ms);
    }
}

int main()
{
    std::thread t1(Writer);
    std::thread t2(Reader, "A");
    std::thread t3(Reader, "\t\tB");
    std::thread t4(Reader, "\t\t\tC");
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}



