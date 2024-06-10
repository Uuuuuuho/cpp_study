#include <iostream>
#include <thread>
#include <windows.h>
#include <chrono>
using namespace std::literals;

// 24 page
// 스레드 우선 순위
// 대부분의 OS 가 제공하는 스레드 기술을 직접 사용하면
// "우선순위"등을 지정할수 있습니다.

// 그런데, std::thread 에는 "우선순위 변경하는 기능이 없습니다."

void foo()
{
    auto tid = std::this_thread::get_id(); // 스레드 ID 얻기
}

int main()
{
    std::thread t(&foo);

    // t로 생성한 스레드의 OS 레벨의 핸들(디스크립터) 얻기
    std::thread::native_handle_type handle = t.native_handle();

    // handle 의 타입은 각 OS 마다 다릅니다. 
    // windows API 에서는 "HANDLE" 이라는 타입입니다.

    // 이제 OS 레벨의API 사용이 가능합니다
    SetThreadPriority((HANDLE)handle, THREAD_PRIORITY_HIGHEST);


    t.join();
}