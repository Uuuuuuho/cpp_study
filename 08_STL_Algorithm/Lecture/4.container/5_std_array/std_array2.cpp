#include <vector>
#include <array>
#include "../../cmc.h"
constexpr std::size_t cnt = 1000000;

/* 핵심 정리

STL vector vs 배열

→ std::vector가 사용하기 편리하고 안전하지만 메모리 할당속도, 컴파일러 최적화 등 고려하면 배열이 빠르다

std::array

모든 요소를 stack에 보관하는 container

→ C++11에서 도입됨

*/
void f1()
{
	for(int i = 0; i < cnt; i++) 
	{
		// std::vector<int> v{1,2,3,4,5};
		std::array<int, 5> v{1,2,3,4,5};
	}
}
void f2()
{
	for(int i = 0; i < cnt; i++) 
	{
		int x[5]{1,2,3,4,5};
	}
}
int main()
{
	chronometry(f1);
	chronometry(f2);
}