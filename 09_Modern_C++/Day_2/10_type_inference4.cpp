#include <iostream>

// 정리!

// 규칙 1. 값타입으로 받을때
//  함수인자의 "const, volatile, reference"제거후 T결정
//  T의 타입은 결국 a의 타입
template<typename T> void foo(T a)
{
	
}
// 규칙 2. 참조로 받을때
// 함수인자의 "reference" 제거후 T의 타입 결정
// const, volatile은 유지
// T가 결정되면 & 를 붙여서 a의 타입결정
// T가 int 라면 a는 int&


// 규칙 3. T&& 일때 : 중요!!! 내일!!!


template<typename T> void goo(T& a)
{
	a = 100;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  	// T : int
	foo(c);  	// T : int
	foo(r);  	// T : int 
	foo(cr); 	// T : int

				/* In VC++ 							*/
	goo(n); 	/* T = int,			a = int& 		*/
	goo(c); 	/* T = const int,	a = const int& 	*/
	goo(r); 	/* T = int,			a = int& 		*/
	goo(cr);	/* T = const int,	a = const int& 	*/
}