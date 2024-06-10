#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <string_view>
#include <condition_variable>
using namespace std::literals;


std::shared_mutex m;

int share_data = -1;

// std::condition_variable cv;  // 반드시 std::unique_lock과 사용해야 합니다.
std::condition_variable_any cv; // std::unique_lock이 아닌 다른
                                // 도구(shared_lock)과 사용가능

bool data_ready = false;

// 어제 shared_mutex(lock) 예제 입니다.
void Writer()
{
    std::this_thread::sleep_for(500ms); // 생산자가 늦게 출발

    while (1)
    {
        {
            std::lock_guard<std::shared_mutex> g(m);
            share_data = share_data + 1;
            std::cout << "Writer : " << share_data << std::endl;
            std::this_thread::sleep_for(1s);
            data_ready = true;
        }
//      cv.notify_one(); // 대기중인 스레드 한개만 깨우게 됩니다.
        cv.notify_all(); // 대기중인 모든 스레드에 신호 전달.(모두 깨우기)

        std::this_thread::sleep_for(10ms);
    }
}

void Reader(std::string_view name)
{
    while (1)
    {
        {
//          std::shared_lock<std::shared_mutex> g(m); // lock_shared()

            std::unique_lock<std::shared_mutex> g(m);

            cv.wait(g, []() { return data_ready; });
                            /* cv가 condition_variable_any이고,
                                g가 shared_lock이므로
                                lock_shared()/unlock_shared를 사용하게 됩니다. */
                
            std::cout << "Reader(" << name << ") : " << share_data << std::endl;
            std::this_thread::sleep_for(500ms);
        }
        std::this_thread::sleep_for(10ms);
    }
}



int main()
{
    std::thread t1(Writer);
    std::thread t2(Reader, "A");
    std::thread t3(Reader, "B");
    std::thread t4(Reader, "C");
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
