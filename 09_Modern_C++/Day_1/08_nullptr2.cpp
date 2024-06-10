#include <iostream>

void foo(void*) { std::cout << "foo" << std::endl; }
void goo(char*) { std::cout << "goo" << std::endl; }

// nullptr 의 원리!!
// => boost 라이브러리에서 아래처럼 만들어서 사용했었습니다.
// => C++11 만들면서는 아래 처럼 만든것이 아니라
//   "키워드로 도입" 되었습니다. 원리는 아래 코드와 같습니다.
struct nullptr_t
{
	// "변환 연산자" 라는 문법입니다.
//	operator void* () { return 0; }

	template<typename T>
	operator T* () { return 0; }
};
nullptr_t mynullptr;

int main()
{
	foo(mynullptr); // mynullptr => void* 로의 암시적 변환 필요
					// "mynullptr.operator void*()"
	goo(mynullptr);
}