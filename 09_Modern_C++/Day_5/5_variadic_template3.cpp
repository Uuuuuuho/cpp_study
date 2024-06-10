#include <iostream>

template<typename ... Types> void foo(Types ... args)
{
	// foo(1,2,3) 으로 사용했다면
	// 
	// 1. 용어 알아 두세요
	// Types : int, int, int  => template parameter pack
	// args  : 1, 2, 3        => function parameter pack

	// 2. pack 에 있는 갯수 조사
	std::cout << sizeof...(Types) << std::endl;
	std::cout << sizeof...(args) << std::endl;
}

int main()
{
	foo(1, 2, 3);
}