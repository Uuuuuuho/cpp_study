#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

void hoo(int&&){}

// template<typename F>
// void chronometry(F f, int& arg)
// {
//     // f(arg); /* 함수 실행 */
//     f(static_cast<int&>(arg));  /*  int& 타입을 int&로 캐스팅하므로 불필요함.
//                                     하지만 있어도 상관없음.
//                                     컴파일러가 무시함.
//                                 */
// }
// template<typename F>
// void chronometry(F f, int&& arg)
// {
//     // f(arg);
//     f(static_cast<int&&>(arg));
// }

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
    /*  Think about casting below. 
        2nd argument of chronometry.
        rvalue : casting to rvalue (받을때 사용한 lvalue인 arg를).
        lvalue : casting to lvalue.
    */
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
