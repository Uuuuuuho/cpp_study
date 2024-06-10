#include <iostream>
#include <thread>
#include <atomic>


// 해결책 3. C++ 표준의 std::atomic 사용
#include <atomic>

std::atomic<long> x = 0;    // x는 long이 아닌 std::atomic입니다.
                            // ++,==,!= 등의 대부분 연산자가 재정의되어 있습니다.

void foo()
{
    for (int i = 0; i < 1000000; ++i)
    {
        ++x;    // 1. x.operator++() 호출됩니다. 아래 코드와 동일합니다.
        x.fetch_add(1); // 2. 위와 동일합니다.
                
        int n1 = x;
        int n2 = x.load();  // 위와 동일

        // 연산자 재정의와 멤버함수 호출의 차이점.
        x.fetch_add(1);
        x.fetch_add(1, std::memory_order_relaxed);  // 2번째 인자 변경 가능
    }
}


int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
    std::cout << x << std::endl;
}
