#include <chrono>
#include <iostream>
#include <thread>
using namespace std::literals;

// 핵심. 종료를 위해서 약속된 변수 전달
// 주스레드가 새로운 스레드를 "원할때 종료되게 하려면"
// 약속된 메시지를 보내야함.

// 이모델은 결국, 주스레드와 foo 를 실행하는 스레드가 서로 협력해야 하는 모델 입니다.
// 이런것을 "cooperative cancelation" 이라고 C# 언어에서는 이야기 합니다.

void foo(bool &quit_signal)
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(500ms);
        std::cout << "foo : " << i << std::endl;
        if (quit_signal) break;
    }
    std::cout << "foo terminated\n";
}

int main()
{
    bool quit = false;
    std::thread t1(foo, std::ref(quit));

    std::this_thread::sleep_for(1s);
    
    quit = true;    // quit signal 전달

    t1.join();
}