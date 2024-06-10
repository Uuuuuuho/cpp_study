#include <iostream>
#include <vector>

std::vector<int> v;

template<typename ... Types>
void foo(Types ... args)
{
	// 핵심 1. 초기값은 0 뿐 아니라 어떠한 객체라도 사용가능합니다.
	//        이항 연산자는 + 뿐 아니라 대부분 연산자도 가능하고
	//        C++은 연산자 재정의 기술이 있으므로 어떤 일도 할수 있습니다.
	// (std::cout << ... << args);
	// (0      +  ...  + args)
	// (((( std::cout << 1 ) << 2) << 3) << 4) << 5)

	// 핵심 2. pack 의 이름뿐 아니라 "pack이름을 사용하는 패턴" 도 가능

//	((std::cout << args << " ") , ...);
	// (pack을 사용하는 패턴     op  ...)   // 이항연산자가 , 

	// ( (std::cout << 1 << " "), ((std::cout << 2 << " ")

	// 아래 코드 해석해 보세요
	(v.push_back(args), ...);
}

// 가변인자 템플릿    : C++11
// fold expression : C++17

int main()
{
	foo(1, 2, 3, 4, 5);
}
