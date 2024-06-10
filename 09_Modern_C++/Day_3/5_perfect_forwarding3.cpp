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

/*  main                chronometry             hoo(int&&) 
    hoo(10)====================================> Ok.
    chronometry(10)====>int&& arg=10으로 받음.
                        hoo(arg)===============> Error.
*/
template<typename F>
void chronometry(F f, int&& arg)
{
    /*  이 함수에 10이 전달되면 "int&& arg = 10"이 되는데
        원래 인자는 10이라는 rvalue인데, 받으면서 사용한 arg lvalue로 변경됨.
    */
    // f(arg); /* 함수 실행 */
    f(static_cast<int&&>(arg)); /* Ok. */
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
