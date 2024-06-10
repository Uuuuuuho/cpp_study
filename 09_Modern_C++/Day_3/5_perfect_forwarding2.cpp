#include <iostream>

/*  Perfect forwarding 
    => 전달받은 인자를 다른 함수에 다시 전달(forwarding) 할때
    => 어떠한 변화도 없이 완벽하게 전달하는 기술.
*/
void foo(int a)  {}
void goo(int& a) { a = 100; }

/*  핵심 1. int&, int&& 버전으로 2개를 제공해야한다.
    핵심 2. 그런데 아래 코드에는 한가지의 문제가 있다.
*/

void hoo(int&&){}

template<typename F>
void chronometry(F f, int& arg)
{
    f(arg); /* 함수 실행 */
}
template<typename F>
void chronometry(F f, int&& arg)
{
    f(arg); /* 함수 실행 */
}

int main()
{
	int n = 10;

	chronometry(foo,10);    /* foo(10) */
	chronometry(goo,n);     /* goo(n)  */

    hoo(10);                /* Ok. */
	chronometry(hoo,10);    /* Error. */

	std::cout << n << std::endl;
}
