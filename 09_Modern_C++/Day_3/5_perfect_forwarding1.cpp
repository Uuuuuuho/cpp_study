#include <iostream>

/*  Perfect forwarding 
    => 전달받은 인자를 다른 함수에 다시 전달(forwarding) 할때
    => 어떠한 변화도 없이 완벽하게 전달하는 기술.
*/
void foo(int a)  {}
void goo(int& a) { a = 100; }

/* 함수의 수행시간을 측정하는 함수 */
template<typename F, typename T>
void chronometry(F f, T arg)    /* arg를 const 속성을 부여하면, f(arg)에서 const 속성을 제거할 수 없음. */
{
    // <====== 시간 기록
    f(arg); /* 함수 실행 */
    // <====== 시간 출력
}
int main()
{
	int n = 10;

	chronometry(foo,10);    /* foo(10) */
	chronometry(goo,n);     /* goo(n)  */

	std::cout << n << std::endl;
}
