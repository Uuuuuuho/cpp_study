#include <iostream>
#include <mutex>
#include <thread>
#include <latch>
#include <string_view>
using namespace std::literals;

std::latch completeWork(3);	// 내부적으로 3을 보관
void foo(std::string_view name)
{
	std::cout << "start  work : " << name << std::endl;
	std::cout << "finish work : " << name << std::endl;
	completeWork.count_down(); 	// 카운트 1 감소
	std::this_thread::sleep_for(30ms);
	std::cout << "go home     : " << name << std::endl;
}

int main()
{
	std::thread t1(foo, "kim"), t2(foo, "lee"), t3(foo, "park");

	completeWork.wait();	// count가 0이 될때까지 대기
												// 세마포어는 0이면 대기
	std::cout << "receive signal" << std::endl;

	t1.join();
	t2.join();
	t3.join();
}
