#include <iostream>
#include <mutex>
#include <thread>
#include <latch>


void foo(std::string name)
{
	std::cout << "start  work : " << name << std::endl;
	std::cout << "finish work : " << name << std::endl;
	std::cout << "go home     : " << name << std::endl;
}

int main()
{
	std::jthread t1(foo, "kim"), t2(foo, "lee"), t3(foo, "park");


	std::cout << "receive signal" << std::endl;
}
