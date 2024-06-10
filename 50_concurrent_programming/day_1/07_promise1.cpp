#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// 31 page

// 핵심 1. 주 스레드가 스레드 함수에서 결과를 얻어오려면
	// 전역변수 또는 변수를 참조로 전달해야함.
	// 그런데, 이 방식은 "연산의 종료를 대기" 할 수 없음.
void add(int a, int b, int &result)
{
	std::this_thread::sleep_for(2s);

	result = a + b;
	std::cout << "thread terminated" << std::endl;
	std::this_thread::sleep_for(2s);
}
int main()
{
	int ret = 0;
	std::thread t(add, 10, 20, std::ref(ret));

	t.join();	// thread termination의 대기
						// 현재는 연산이 종료되었는지를 대기하는 방법은 없다.

	std::cout << ret << std::endl;
}



