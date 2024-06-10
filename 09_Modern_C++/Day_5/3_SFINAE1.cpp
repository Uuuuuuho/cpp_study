#include <iostream>


template<typename T>
//int foo(T a)            { std::cout << "T" << std::endl; return 0; }
typename T::type foo(T a) { std::cout << "T" << std::endl; return 0; }
// typename int::type foo(int a) {} 


int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	foo(3); // 1. 인자를 보고 함수를 결정하므로 이순간
			//    foo(T) 버전을 선택하게 됩니다.
			// 2. T=int 로 추론되고 실제 함수를 생성하게 됩니다.
			// 3. 그런데, "int::type" 이라는 표기법은 없으므로
			//		함수 생성실패!!
			// 4. 이 경우 에러는 아니고, 후보에서 제외 됩니다.
			// 5. 그래서 foo(...) 호출 됩니다.

	// 이 현상을 "SFINAE" 라고 합니다.
	// 
	// => Substitution Failure Is Not An Error.

}
