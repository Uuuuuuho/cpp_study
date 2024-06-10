#include <thread>
#include <atomic>
#include <cassert>

std::atomic<int> data1 = 0;
std::atomic<int> data2 = 0;

int main()
{
    // memory_order_seq_cst 반드시 순차적으로 실행되어야한다.
    data1.store(100, std::memory_order_seq_cst);
    data2.store(200, std::memory_order_seq_cst);
    data2.store(300);       // memory_order를 전달하지 않으면
                            // default가 "std::memory_order_seq_cst"입니다.
                            // 일반적으로 가장 오버헤드가 큽니다.
}
// C++ memory_order : 추상적 개념.
// 해당 명령을 어떻게 기계어로 구현하는지 "각 CPU 환경"에 따라 다릅니다.

// relaxed : 동시 접근만
// release-acquire : release 이전의 코드는 acquire 이후에 visible해야함.
// seq_cst : 순차 실행 보장
