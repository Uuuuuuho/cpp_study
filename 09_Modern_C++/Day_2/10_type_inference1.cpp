#include <iostream>

// 규칙 1. 인자가 값 타입(T) 일때
// => 함수 인자가 가지고 있는 "const, volatile, reference를
//    모두 제거후 T의 타입을 결정
template<typename T> void foo(T a)
{
	// T의 타입을 확인하는 방법
	// 1. RTTI 기술 사용
	// => 사용하지 마세요
	// => C++ RTTI 는 const, volatile, reference 를 제거한
	//    타입의 이름이 출력됩니다.
	std::cout << typeid(T).name() << std::endl;

	// 2. godbold.org에서 확인

	// 3. 생성된 함수의 이름을 출력
	std::cout << __func__ << std::endl;

	std::cout << __FUNCSIG__ std::endl;
				/* 	__FUNCSIG__ : 함수 인자를 포함한 이름 출력
								  단, VC++ 전용 매크로
					__PRETTY_FUNCTION__ : g++ 전용 매크로
				*/
}
int main()
{
	/* Pass type explicitly. */
	foo<int>(3);
	foo<double>(3);
	foo<const int>(3);
}