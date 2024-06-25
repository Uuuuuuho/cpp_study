#include <print>


/* 핵심정리

std::array (C++11 ~)
→ <array>
→ 모든 요소를 스택에 보관하는 컨테이너
→ “raw array”와 거의 동일한 성능
→ 다양한 멤버함수가 있어서 “raw array”보다 편리하고 안전하다.

*/
template<typename T, int N>
struct array
{
	T buff[N];	

	int size() const { return N;}
};

int main()
{
	array<int, 5> a{1, 2, 3, 4, 5};

	std::println("{}", sizeof(a)); // 20
	std::println("{}", a.size());  // 5 
}