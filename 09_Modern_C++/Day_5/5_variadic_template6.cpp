#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 에 있는 모든 요소를 꺼내고 싶다면
	// args 에서 2번째 값을 꺼내고 싶다?? => 한번에 할수 없습니다.

	// 방법 1. pack expansion
	//     2. recursive 와 유사 코드
	//     3. fold expression - C++17

	// 방법 1.
	// => 모든 요소가 동일하다는 확신이 있으면 배열에 담을수 있습니다.
	int x[] = { args... }; // {1,2,3}

	// => 요소의 타입이 다르면 tuple 에 담으세요
	std::tuple<Types...> t(args...);

	auto e1 = std::get<0>(t);
	auto e2 = std::get<1>(t);
}


int main()
{
	foo(1, 2, 3);
}
