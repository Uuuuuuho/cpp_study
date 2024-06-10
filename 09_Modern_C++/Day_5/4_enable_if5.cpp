#include <iostream>
#include <type_traits>

// 리턴 타입 자리에 "std::enable_if_t<조건, 반환타입>" 표기해보세요

template<typename T>
std::enable_if_t<std::is_pointer_v<T>, void>
printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T>
std::enable_if_t<!std::is_pointer_v<T>, void>
printv(const T& v)
{
	std::cout << v << std::endl;
}



int main()
{
	int n = 10;

	printv(n); //<!!
	printv(&n);
}