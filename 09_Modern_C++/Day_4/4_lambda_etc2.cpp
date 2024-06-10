#include <iostream>
// 함수 인자로 auto 를 사용할수는 없습니다.
// void foo(auto n) {} 

int main()
{
//	foo(1);
//	foo(3.4);
	
	auto f = [](int a, int b) { return a + b; };

	int    n = f(1, 2);
	double d = f(3.2, 3.2);

	// generic lambda : 인자로 auto 를 사용하는 람다. C++14부터지원
	auto add = [](auto a, auto b) { return a + b; };

	std::cout << add(1,   2) << std::endl;
	std::cout << add(1.1, 2.1) << std::endl;
	std::cout << add(1,   2.1) << std::endl;
	std::cout << add(1.1, 2) << std::endl;
	
}