#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
template<typename ... Types> void foo(Types ... args)
{
	// args 의 모든 요소를 화면 출력 하고 싶다.
//	printv(args...); // printv(E1, E2, E3); 이므로 error

//	printv(args)...; // printv(E1), printv(E2), printv(E3)  
					 // 의 의도 인데 - error

	// pack expansion 은 모든 곳에서 가능하지 않습니다.
	// 1. 함수 호출의 () 안이나			: goo(args...)
	// 2. {} 초기화					: { args... }
	// 3. 템플릿 인자 <> 등에서만 가능합니다. <Types...>

	int x[] = { ( printv(args), 0)... };
		// { (printv(E1), 0), (printv(E2), 0), (printv(E3), 0) };
			
}


int main()
{
	foo(1, 2, 3);
}