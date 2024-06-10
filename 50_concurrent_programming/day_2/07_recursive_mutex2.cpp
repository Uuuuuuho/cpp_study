#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

class Machine
{
    std::mutex m;
    int shared_data = 0;
public:
    void f1()
    {
        m.lock();
        shared_data = 100;
        m.unlock();
    }
    void f2()
    {
        /*  멤버 함수가 다른 멤버 함수를 호출하는 경우에
            lock을 2회이상 하게 되는 경우가 있습니다.
        */
        m.lock();
        shared_data = 200;
        m.unlock();
    }
};
int main()
{
    Machine m;
    std::thread t1(&Machine::f1, &m);
    std::thread t2(&Machine::f2, &m);
    t1.join();
    t2.join();
}



