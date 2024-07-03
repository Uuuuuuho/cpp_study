#include <set>
#include <functional>
#include "cmc.h"

/* 
    std::set에 새로운 요소를 삽입하면
    → 기존의 요소와 “크기 비교”를 통해서 삽입될 위치를 결정
    → set의 2번째 템플릿 인자로 전달된 함수 객체를 사용해서 비교(policy base design)

    ```cpp
    tempalte<
    typename Key,
    typename Compare = std:;less<Key>,
    typename Allocator = std:;allocator<Key>
    > class set;
    ```
*/

template<typename T>
struct absLess
{
	bool operator()(const T& a, const T& b) const
	{
		return abs(a) < abs(b);	
	}	
};
int main()
{
//	std::set<int> s; // <, -7, 3, 4, 5
//	std::set<int, std::greater<int> > s;
	std::set<int, absLess<int> > s; // 3, 4, 5, -7

	s.insert(5);
	s.insert(3);
	s.insert(-7);
	s.insert(4);

	show(s);
}