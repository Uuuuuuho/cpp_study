#include <iostream>
#include <mutex>
#include <thread>
#include <latch> // C++20 입니다
#include <string_view>
using namespace std::literals;

std::latch completeWork(3);	// 내부적으로 3을 보관


void foo(std::string_view name)
{
	std::cout << "start  work : " << name << std::endl;
	std::cout << "finish work : " << name << std::endl;

//	completeWork.count_down(); // 카운트 1감소


	completeWork.arrive_and_wait(); // 카운트 감소 하고, 카운트가 0이 될때까지대기

	std::cout << "go home     : " << name << std::endl;
	completeWork.arrive_and_wait(); // latch는 재사용이 안됨.
}

int main()
{
	std::thread t1(foo, "A"), t2(foo, "B");

	std::this_thread::sleep_for(1s);

	std::thread t3(foo, "C");

	t1.join();
	t2.join();
	t3.join();	
}