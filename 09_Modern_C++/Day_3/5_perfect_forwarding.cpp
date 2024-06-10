#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }		// 1
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }	// 2
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }		// 3

int main()
{
	foo(10);

	int&& r = 10;
	
	foo(r);     /*  1번으로 감.
                    int&& r = 10에서
                    "10은 rvalue이지만 r은 lvalue"임.
                    이름이 있고, 단일식을 벗어나서 사용가능함.
                */
    /* 타입과 value의 속성을 혼돈하면 안됨. */
    int n = 0;

    /*          타입     value 속성
        n       int     lvalue
        n+1     int     rvalue
        10      int     rvalue
        r       int&&   lvalue

        foo(int&) : 인자로 int& 타입을 받겠다는것이 아니라
                    인자로 lvalue를 받겠다는 것.
        foo(int&&): 인자로 rvalue를 받겠다는 것.
    */

    int&& r2 = 10;
    foo(r2); /* Call foo(int&) */
    foo(static_cast<int&&>(r2));    /* Call foo(int&&) */
    /*  r2 type이 int&&인데 같은타입인 int&&으로 casting 하는 것이 아닌가? 
        static_cast<type&&>는 타입 캐스팅이 아니라 value 속성에 대한 변경이다.
    */
    foo(static_cast<const int&>(r2));    /* Call foo(const int&) */
}







