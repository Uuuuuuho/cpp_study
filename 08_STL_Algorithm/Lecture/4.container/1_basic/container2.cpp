#include <stack>
#include <vector>
#include <print>

/*  컨테이너가 가진 대부분의 멤버 함수는 “반환과 제거를 동시”에 하지 않는다.

    v.back()	    마지막 요소를 반환(reference).
                    요소는 제거되지 않는다.

    v.pop_back()	마지막 요소를 제거만 한다.
                    반환하지 않는다.(void 반환)

설계 의도
→ 예외 안정성(exception safety)의 강력 보장을 지원하고
→ 값 반이 아닌 참조(reference) 반환으로 임시객체를 제거할 수 있다.

STL의 공통적인 특징

1. member type이 있다.
2. 멤버 함수는 반환과 제거를 동시에 하지 않는다.
3. 단위 전략 디자인(policy base design)을 많이 사용한다. (allocator, compare, hash …)

*/

int main()
{
	std::vector v{1, 2, 3, 4};

//	auto n1 = v.pop_back(); // error
	auto n2 = v.back();     // ok. 단, 제거 안됨
	v.pop_back();

	std::stack<int> s;
	s.push(10);
	s.push(20);
	std::println("{}", s.top()); // 20
	s.pop();
	std::println("{}", s.top()); // 10
}