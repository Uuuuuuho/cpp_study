// 17_static_if - 51 page
#include <type_traits>
template<typename T>
void foo(T a)
{
	// if  : 실행시간 제어문
	//		 컴파일 할때 false 로 결정되어도 
	//	     인스턴스화(템플릿 => C++함수)에 포함됩니다.
//	if (false)
//		*a = 10; // 이 코드는 에러일까요 ??

	// if constexpr : 컴파일 시간 제어문
	//				  조건이 false 라면 인스턴스화에 포함안됨
	//				  C++17 에서 도입된 문법
	if constexpr (false)
		*a = 10; // 에러 아님.

	// 실전에서는 아래 처럼 사용합니다 - 목요일날자세히
	if constexpr (std::is_pointer<T>::value)
	{
		// 이부분은 T가 포인터인 경우만 인스턴스화에 포함되고
		// T가 포인터가 아니면 컴파일 시에 함수 생성시 제거됩니다.
	}
}
int main()
{
	foo(0); 
}