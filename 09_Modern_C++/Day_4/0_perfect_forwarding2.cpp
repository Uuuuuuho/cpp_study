#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

void foo() {}
void foo(int a) {}
void foo(int a, int b) {}

int main()
{
    /*  함수 직접 호출시
        => 인자를 보고 어느 함수인지 찾을 수 있음.
    */
	foo();
	foo(10);
	foo(10, 20);
 
	// chronometry(foo, 10); // ?
    chronometry(static_cast<void(*)(int)>(foo),10); /* void foo(int a)를 call함. */
}









