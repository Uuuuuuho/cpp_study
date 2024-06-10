#include <iostream>
#include <thread>


void foo(int a, double d) {}

struct Machine
{
    void Run(int a, double d) {}
};

struct Work
{
    void operator()(int a, double b) const {}
};

// std::thread 의 생성자를 생각해 봅시다.
class mythread
{
public:
    // 규칙 1. 생성자 인자는 반드시 "()" 로 호출가능한 것이 전달되어야 합니다.
    
    template<typename T, typename ... Types >
    mythread(T&& func, Types&& ... args)
    {
        // 1. 각 OS의 시스템 call 을 사용해서 스레드 생성
        // 2. 생성된 스레드가 생성자 인자로 전달된 함수 실행.

        // 아래 처럼 하면 func 는 "일반함수", "함수객체" 만 됩니다.
        // 멤버 함수가 안됩니다.
        // func( std::forward<Types>(args)... ); // 새로운 스레드가 실행하도록.. 코드 작성..
        
        // 아래 처럼 하면 멤버 함수도 됩니다.
        std::invoke(func, std::forward<Types>(args)...);
    }
};
int main()
{
    mythread t1(&foo, 3, 3.4);

    Work w;
    mythread t2(w, 3, 3.4); // w(3, 3.4) => w.operator()(3, 3.4)
//  mythread t2(&w, 3, 3.4);// &w 는 Work* 입니다. ()로 호출안됩니다.

    Machine m;
    mythread t3(&Machine::Run, &m, 3, 3.4);

    // C언어  : 함수와 함수 포인터 뒤에만 ()를 붙일수 있습니다.
    //C++언어 : 함수, ()연산자를 재정의한 객체, 함수에대한 참조 도
    //         ()를 붙일수 있습니다.

}






struct FUNC
{
    int& value;
    FUNC(int& r) : value(r) {}

    void operator()() const
    {
        value = 10;
    }
};