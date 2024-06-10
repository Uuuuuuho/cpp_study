#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

    /* 1. 람다표현식에서 전역변수 
       => Ok. 람다표현식에서 전역변수 사용가능.
    */
	auto f1 = [](int a) { return a + g; };
            /* class xxx{operator()(int){a+g;}}; xxx() */

    /* 2. 람다표현식에서 main 지역변수 사용.
       => 기본적으로 접근할 수 없음.
       => 접근하려면 캡쳐해야한다.
    */

    /* "[]"가 캡처임. */
    // auto f2[](int a){ return a + v1 + v2;}; /* Error. */
    auto f3 = [v1, v2](int a){return a + v1 + v2;}; /* Ok. */

    auto f4 = [v1, v2](int a){ v1 = 100; return a;};  /* Error. */

    auto f5 = [v1, v2](int a)mutable{v1 = 100; return a;}; /* Ok. */
}





