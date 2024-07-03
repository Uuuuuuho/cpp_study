#include <list>
#include <vector>
#include <deque>

/* 핵심 정리
    std::stack의 구현 원리
    → 2번째 템플릿 인자를 사용해서 stack이 내부적으로 사용하는 컨테이너의 선택 가능.
    → sequence container의 “멤버 함수 이름을 변경”해서 stack처럼 사용할 수 있도록 만든 것
    → adaptor 디자인 패턴
    → “stack adaptor”라는 용어
    
    STL이 제공하는 container adaptor

    C++98
        std::stack, std::queue, std::priority_queue
    C++23
        std::flat_set, std::flat_multiset, std::flat_map, std::flat_multimap
*/

template<typename T, typename C = std::deque<T> >
class stack
{
	C c;
public:
	void push(const T& a) { c.push_back(a);}
	void pop()            { c.pop_back();}
	T&   top()            { return c.back();}
};
int main()
{
	std::stack<int> s;
	s.push(10);
	s.push(20);

	std::stack<int, std::list<int> > s1;
	std::stack<int, std::vector<int> > s2;
}