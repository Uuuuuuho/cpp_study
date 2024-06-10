#include <iostream>
#include <thread>
#include <vector>
#include <Windows.h>
// 17 page

// std::this_thread 안에 4개의 도움 함수가 있습니다.

int main()
{
    // get_id() : 현재스레드의 ID 값 반환
    std::cout << std::this_thread::get_id() << std::endl;

    // class thread 
    // { 
    //      using id = 구현에따라 다름.; 보통 "struct thread_id {}"
    // }
    std::thread::id tid1 = std::this_thread::get_id();

    // 특징 1. 정수 변환 안됩니다.
//  int n = tid1; // error.

    // 스레드 ID를 vector에 담으려면
    std::vector<std::thread::id> v;

    // 해쉬가능합니다. - unordered_xxx 자료구조에 담을수 있습니다.
    std::hash<std::thread::id> h;

    
    // ==, != 연산도 가능합니다
    auto t1 = std::this_thread::get_id();
    auto t2 = std::this_thread::get_id();

    t1 == t2;
    t1 != t2;

    // implementation
    std::cout << std::this_thread::get_id() << std::endl;
    std::cout << GetCurrentThreadId() << std::endl;
}
// 핵심 : 스레드 id를 정수 처럼 생각하지는 마세요.!
//       "고유의 타입이 있다" 라고 생각하세요

