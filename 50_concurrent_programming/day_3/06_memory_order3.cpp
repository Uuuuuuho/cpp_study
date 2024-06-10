#include <thread>
#include <atomic>

// std::memory_order_relaxed : 동시접근에 대한 것만 보장합니다.
                        //     reordering 발생할 수 있습니다.
std::atomic<int> x = 0;
std::atomic<int> y = 0;

void foo()
{
    // A,B의 각 연산은 스레드에 안전합니다. (동시접근 안됨)
    // 하지만, A, B의 실행 순서는 완벽히 보장하지 않습니다.
    int n1 = y.load(std::memory_order_relaxed);     // A 
    x.store(n1, std::memory_order_relaxed);         // B
}

void goo()
{
    int n2 = x.load(std::memory_order_relaxed);
    y.store(100, std::memory_order_relaxed);
}

int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join(); t2.join();
}