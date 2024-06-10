#include <thread>

// 아래 코드는 x,y가 일반 전역변수.
int x = 0;
int y = 0;

void foo()
{
    int n1 = y; // goo에 y=100이 있으므로
                // 이 한줄이 스레드에 안전하지 않습니다.
    x = n1;
}
void goo()
{
    int n2 = x;
    y = 100;
}
int main()
{
    std::thread t1(foo);
    std::thread t2(goo);
    t1.join(); t2.join();
}