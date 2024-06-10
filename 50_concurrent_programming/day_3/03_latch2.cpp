#include <iostream>
#include <mutex>
#include <thread>
#include <latch>
#include <string_view>
using namespace std::literals;

std::latch completeWork(3);	// 내부적으로 3을 보관
std::latch gohomeLatch(1);  // 초기 카운트 1인 latch

void foo(std::string_view name)
{
	std::cout << "start  work : " << name << std::endl;
	std::cout << "finish work : " << name << std::endl;
	completeWork.count_down(); 	// 카운트 1 감소
  gohomeLatch.wait();         // 작업이 종료된 모든 스레드는 여기서 대기.
	// std::this_thread::sleep_for(30ms);
	std::cout << "go home     : " << name << std::endl;
}

int main()
{
	std::thread t1(foo, "kim"), t2(foo, "lee"), t3(foo, "park");

	completeWork.wait();	// count가 0이 될때까지 대기
												// 세마포어는 0이면 대기
	std::cout << "receive signal" << std::endl;

  std::this_thread::sleep_for(3s);
  gohomeLatch.count_down();

	t1.join();
	t2.join();
	t3.join();
}
