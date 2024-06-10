/*  g++ 컴파일러와 vc 컴파일러로 어셈블리 코드 만드는 방법
    => g++ reorder1.cpp –S –masm=intel -O2
    => cl reorder1.cpp /FAs /c /O2

    요즘은 "godbolt.org" 사이트에서 어셈코드 볼수 있습니다.

    결론
    1. 동시 접근을 막는것만 고려하는 것이 아니라
    2. reordering에 대한 문제도 고려되어야합니다.
 */
#include <atomic>

int a = 0;
int b = 0;

// thread A
void foo()
{
    a = b + 1;

    //    __asm{ mfence } // 메모리 펜스 명령, 위 코드는 이 펜스를 넘어 올수 없다

    //  std::atomic_thread_fence( std::memory_order_relaxed);
    std::atomic_thread_fence(
        std::memory_order_seq_cst);

    b = 1;
}

// thread B
void goo()
{
    if (b == 1)
    {
        // a == 1 을 보장할수 있을까 ?
    }
}