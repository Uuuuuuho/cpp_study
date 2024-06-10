#include <iostream>
#include <thread>
#include <string_view>

// 73 page

int next3times()
{
	static int n = 0;	// not useful for multi-threading
	n = n + 3;
	return n;
}

void foo(std::string_view name)
{
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
	std::cout << name << " : " << next3times() << std::endl;
}

int main()
{
	// foo("A");

	std::thread t1(foo,"A");
	std::thread t2(foo,"\tB");

	t1.join();
	t2.join();
}



