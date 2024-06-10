#include <iostream>

// 방법 2. recursive 유사코드!

// 1번째 인자는 독립된 변수 명으로 받으세요

void foo() {}   // 재귀의 종료를 위해(아래 C++17 코드는 필요없음)

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

//	foo(args...);	// foo(3.4, 'A')
					// foo('A')
					// foo()

	// C++17 부터는 아래 처럼 하세요
	if constexpr (sizeof...(args) > 0)
		foo(args...);
}

int main()
{
	foo(1, 3.4, 'A');  // value : 1, args : 3.4, 'A'
}