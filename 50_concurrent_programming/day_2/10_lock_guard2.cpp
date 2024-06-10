#include <iostream>
#include <thread>
#include <mutex>
#include <exception>

std::mutex m;

void foo()
{
//	std::lock_guard<std::mutex> lg(m); // m.lock() 으로 lock 획득

	// lock()이 아닌 다른 방법으로 lock 을 획득
	if (m.try_lock())
	{
		// lock()은 다른 방법으로 획득했지만, unlock 만큼은
		// lock_guard로 안전하게 관리하고 싶다.
		// std::lock_guard<std::mutex> g(m);  // 생성자에서 다시 m.lock()수행

		std::lock_guard<std::mutex> g(m, std::adopt_lock); // ok.
						// 1. 이미 lock은 했으므로 생성자에서 lock하지말고
						// 2. 소멸자에서 unlock을 해달라.

		std::cout << "using shared data" << std::endl;

	}
}

int main()
{
	std::thread t1(foo);
	std::thread t2(foo);
	t1.join();
	t2.join();
}
