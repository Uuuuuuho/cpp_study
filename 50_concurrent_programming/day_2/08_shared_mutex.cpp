#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string_view>
using namespace std::literals;

// 규칙
// 1. 쓰는동안 다른 스레드가 읽을 수 없어야한다.
// 2. 쓰는동아 다른 스레드가 쓸 수 없어야한다.
// 3. 읽는동안 다른 스레드가 쓸 수 없어야한다.
// 4. 읽는동안 다른 스레드가 읽을 수 ??? <= 핵심.

std::mutex m;
int share_data = 0;

void Writer()
{
    while (1)
    {
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
        m.lock();
        std::cout << "Reader(" << name << ") : " << share_data << std::endl;
        std::this_thread::sleep_for(500ms);
        m.unlock();
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



