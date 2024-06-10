#include <iostream>
#include <thread>
#include <mutex>
using namespace std::literals;

class Singleton
{
private:
    Singleton()
    {
        std::cout << "start ctor" << std::endl;
        std::this_thread::sleep_for(3s);
        std::cout << "finish ctor" << std::endl;
    }
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    // 오직 한개의 객체를 static 지역변수로 만든 싱글톤 모델.
    // static 지역변수
    // 1. 함수를 수십번 호출해도 최초 호출시 한개만 생성됩니다.
    // 2. 함수를 여러개의 스레드가 실행해도 모든 스레드가 공유, 즉, 한개 입니다.
    // => 결국 한개의 객체 입니다.

    // => 먼저 도착한 스레드가 "Singleton 생성자"를 실행하고 있다면
    // => 나중에 도착한 스레드는 "생성자 호출이 종료" 될때 까지 대기하게 됩니다.
    // => 즉, 아래 코드는 멀티 스레드에도 안전한 코드 입니다.
    // => 결국, 생성자가 "call_once"로 실행
    static Singleton& getInstance()
    {
        std::cout << "start getInstance" << std::endl;
        static Singleton instance;
        std::cout << "finish getInstance" << std::endl;

        return instance;
    }
};
void foo()
{
    Singleton& s = Singleton::getInstance();
    std::cout << &s << std::endl;
}
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);
    t1.join();
    t2.join();
    t3.join();
}



