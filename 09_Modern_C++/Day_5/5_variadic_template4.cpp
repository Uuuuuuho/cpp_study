#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// foo(1,2,3) 이므로
	// args : 1, 2, 3

//	goo(args); // error. pack 이름을 인자로 사용할수 없습니다.


	// 핵심 1. pack expansion : pack안의 요소를 , 로 나열하는것

	// "pack 이름을 사용하는 패턴"... => "E1패턴", "E2패턴", "E3패턴"

	goo(args...); // ok.  goo(E1, E2, E3) 의 의미

	goo((++args)...);	// ok. goo( ++E1, ++E2, ++E3)
						// <= () 없어도 됩니다.

//	goo( hoo(args...)); // goo(hoo(E1,E2,E3)) 인데.. hoo 는 인자가 한개
						// 따라서 error

	goo( hoo(args)...); // goo(hoo(E1), hoo(E2), hoo(E3))
}


int main()
{
	foo(1, 2, 3);
}