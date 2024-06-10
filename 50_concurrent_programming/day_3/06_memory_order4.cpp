#include <thread>
#include <atomic>
#include <cassert>

std::atomic<int> data1 = 0;
std::atomic<int> data2 = 0;
std::atomic<int> flag = 0;

void foo()
{
    data1.store(100, std::memory_order_relaxed);
    data2.store(200, std::memory_order_relaxed);
    // flag.store(1, std::memory_order_relaxed);       // 동시 접근만 보장함.
                                                    // 위에 코드가 아래로 내려올 수 있습니다.
    flag.store(1,std::memory_order_release);
                                    // 이 코드는 이전의 모든 명령은
                                    // acquire 이전에 반드시 visible 되어야한다.
}

void goo()
{
    // if ( flag.load( std::memory_order_relaxed) > 0)
    if ( flag.load( std::memory_order_acquire) > 0)
    {
        assert(data1.load(std::memory_order_relaxed) == 100);
        assert(data2.load(std::memory_order_relaxed) == 200);
    }
}

int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join(); t2.join();
}