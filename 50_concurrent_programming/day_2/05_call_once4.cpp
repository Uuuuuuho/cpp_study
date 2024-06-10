#include <iostream>
#include <thread>
#include <mutex>
using namespace std::literals;

class Object
{
private:
    /* data */
public:
    Object();
    ~Object();
    void init() {std::cout << "init called" << std::endl;};
};

Object::Object()
{
    std::cout << "start Object()" << std::endl;
    std::this_thread::sleep_for(3s);
    std::cout << "end Object()" << std::endl;
}

Object::~Object()
{
}

void foo()
{
    /*  핵심 1. static local variable로 만든 객체의 생성자는 
                멀티스레드 환경에서도 한번만 호출됨을 보장합니다.
                늦게 도착한 스레드 생성자 호출 종료를 대기(blocking)됩니다.
    */
	// static Object obj;

    /*  핵심 2. 멤버함수 호출은 한번만 호출되는 것이 아님.
                스레드가 여러개라도 한번만 실행되게 하려면 call_once를 사용해야함.
    */

    // obj.init();

   /*  핵심 3.  일반 지역변수로 만드는 객체
                스레드당 따로 객체가 생성(stack)되므로, 생성자도 각각 호출
                한개의 생성자 호출이 끝날때를 대기하는 것도 아님.
   */
    // Object obj2;

    /*  핵심 4. 동적으로 객체 생성
                역시 2개의 객체를 생성하므로 생성자도 2회 호출
                각 객체의 주소를 지역변수 p에  보관하는데, p는 스레드당 한개씩
    */
    Object* p = new Object;
    delete p;
}

int main()
{
	std::thread t1(foo);
	std::thread t2(foo);

	t1.join();
	t2.join();
}