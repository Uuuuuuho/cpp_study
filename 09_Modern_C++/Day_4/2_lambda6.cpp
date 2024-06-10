#include <iostream>

int main()
{
	// 람다표현식의 정확한 모양. return type에 대해 명시해야함.
	auto f1 = [](int a, int b) ->int { return a + b; };

	// 1. return 문장이 한개라면 리턴 타입 생략가능
	auto f2 = [](int a, int b) { return a + b; };


	// 2. return 문장이 여러개라도 동일 타입이면 생략 가능
	auto f3 = [](int a, int b) { if (a == 1) return a; 
								return b; };

	// 3. 다른 타입을 반환하는 return 문이 있으면 표기해야 한다.
	// =>아래 코드는 리턴 타입 표기하지 않으면 error
	auto f3 = [](int a, double b) { if (a == 1) return a;
							return b; };
}
