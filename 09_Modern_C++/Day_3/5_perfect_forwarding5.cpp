#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }
void hoo(int&&){}

/*  핵심 : 완벽한 전달을 하려면
    1. 인자를 받을때 T&&로 받을 것.
    2. 인자를 다른곳에 전달할때 "std::forward<T>(arg)"로 묶어서 전달.

    T&& 기술이 대부분 "완벽한 전달"할때 사용되기 때문에
    "forwarding reference"라고 불림.
*/
template<typename F, typename T>
void chronometry(F f, T&& arg)
{
    f(static_cast<T&&>(arg));

    /*  C++ 표준에서 위의 작업에 대한 새로운 함수를 제공함. */
    f(std::forward<T>(arg));
}
int main()
{
	int n = 10;

	chronometry(foo,10);    /*  T = int, chronometry(int&&)
                                static_cast<int&&>(arg)
                            */
	chronometry(goo,n);     /*  T = int&, chronometry(int&)
                                static_cast<int&>(arg)
                            */

    hoo(10);                /*  */
	chronometry(hoo,10);

	std::cout << n << std::endl;
}
