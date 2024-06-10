#include <iostream>

// function object(함수 객체)
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체

// 왜? 일반함수를 사용하지 않고 함수객체를 사용하나요 ?
// 1. 상태를 가지는 함수
// 2. 클로져 가능
// 3. 빠르다.
// 4. ADL 회피 등.. 다양한 장점..

// 주의 사항 : operator() 는 대부분 상수 멤버 함수로 만들게 됩니다.
struct Plus
{
	// inline 또는 constexpr 을 많이 사용
	inline int operator()(int a, int b) const
	{
		return a + b;
	}
};

void foo(const Plus& f)
{
	int n = f(1, 2); // f.operator()(1, 2) 인데..
					 // f 는 상수 객체 입니다.
					 // "상수객체는 상수 멤버함수만 호출가능" 하므로
					 // 이 코드가 되려면 () 가 상수 멤버 함수이어야합니다.
}


int main()
{
	Plus p;	// p 는 함수가 아니라 객체(구조체)입니다.!!	

	int n = p(1, 2); // 객체인 p를 함수 처럼 사용합니다.
					 // 함수 객체(function object)라고합니다.
					 // p.operator()(1, 2)
	int n2 = p.operator()(1, 2); // ok. 이렇게 호출도 가능	
}