#include <iostream>
#include <string>
#include <thread>

// 기본 OS가 제공하는 스레드 기능
// 함수 모양에 제약이 있다. (인자는 주로 void*)

// C++ thread : 스레드로 수행할 함수의 모양에 제약이 없음.

void f1() { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100; }

int main()
{
    int n = 0;
    std::string s = "hello";

    // 인자 전달 방법
    std::thread t1(&f1);
    std::thread t2(&f2,5,3.4);
    // std::thread t3(&f3,5, n, std::move(s)); // error.
    std::thread t3(&f3,5, std::ref(n), std::move(s)); // inter-thread parameter 사용에 있어서 race condition이 발생할 수 있으므로 프로그래밍 단계에서 주의가 필요함.

    t1.join();
    t2.join();
    t3.join();

    // 단, 스레드간 참조로 전달은 아주 위험하므로 주의해서 사용할 것.
}

