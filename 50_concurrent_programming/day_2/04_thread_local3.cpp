#include <iostream>
#include <thread>
#include <string_view>

// 지역변수 : 스택에 놓이고, 스레드 별로 따로 생성, 함수 호출 종료시 파괴
// 전역변수 : data 메모리,  모든 스레드 공유,     함수 호출 종료 해도 파괴안됨
// (static지역)

// TLS ( Thread Local Storage) : 스레드 별로 따로 생성, 함수 호출 종료해도 파괴 안됨
//							    "스레드 별 static 지역변수"

int gx = 0;

void foo(std::string_view name)
{
	int lx = 0;
	static int sx = 0;

	std::cout << name << " : " << &lx << std::endl;
	std::cout << name << "_gVar : " << &gx << std::endl;
	std::cout << name << "_sVar : " << &sx << std::endl;

}

int main()
{
	std::thread t1(foo, "A");
	std::thread t2(foo, "B");

	t1.join();
	t2.join();
	// foo("Test");	// thread로 수행하지 않는 경우, stack address는 안바뀜.
}