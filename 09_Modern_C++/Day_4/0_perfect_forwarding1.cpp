
#include <iostream>
template<typename F, typename T>
void chronometry(F f, T&& arg) // int&& arg = 0 by type inferencing.
{							   // foo(arg); // error
							   // std::nullptr_t arg = nullptr;
							   // foo(arg); // ok	
	f(std::forward<T>(arg));
}
// 인자로 포인터(주소)를 요구!!
void foo(int* p) {}

int main()
{
	foo(0); // ok. 0전달 가능!!

//	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // ok.. 
}
