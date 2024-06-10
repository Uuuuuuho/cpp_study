// 7_가변인자템플릿7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// 아래 chronometry 는 인자라 한개인 함수만 forwarding 합니다.
/*
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& args)
{
	return f( std::forward<T>(arg)); 
}
*/

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
//	return f( std::forward<T>(args...) ); // forward 의 인자가 3개

	return f(std::forward<Types>(args)...);
		// f(std::forward<T1>(E1), 
		//   std::forward<T2>(E2),
		//   std::forward<T2>(E3));
}
// 가변인자 템플릿은 사용하는 용도가 거의 정해져 있습니다.
// 1. 위와 같은 완벽한 전달기술
// 2. tuple 같은 클래스 만들때..
// => 그래서, 위와 같은 종류의 함수를 만들때만 사용하면 됩니다.


int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}