
#include <array>
#include "cmc.h"

/* 
std::array를 move 하는 경우
요소의 타입이 
→ “move를 지원하는(movable)” 타입인 경우, move constructor가 사용됨.
→ “move를 지원하지 않는” 타입인 경우, copy constructor가 사용됨.
에 따라 다르다

std::array의 복사 생성자와 이동 생성자

*/

int main()
{
	std::array<int, 3> a1{1,2,3};
	std::array<int, 3> a2{1,2,3};

	std::array<int, 3> a3 = a1;
	std::array<int, 3> a4 = std::move(a2);

	show(a1);
	show(a2);
	show(a3);
	show(a4);
}