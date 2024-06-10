#include <iostream>
#include <mutex>
#include <thread>
// #include <latch> // C++20 ???
#include <barrier>
#include <string_view>
using namespace std::literals;

// barrier? ???? ??? ??? ????????.
void oncomplete() noexcept
{
  std::cout << "============= on complete ==============" << std::endl;
}

// std::latch completeWork(3);	// ????? 3? ??
std::barrier completeWork(3, oncomplete); // ??? ????
                                          // ???? 0???
                                          // oncomplete ??

void foo(std::string_view name)
{
	std::cout << "start  work : " << name << std::endl;
	std::cout << "finish work : " << name << std::endl;
  completeWork.arrive_and_wait();

	std::cout << "go home     : " << name << std::endl;
  completeWork.arrive_and_wait();
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