#include <vector>
#include <list>
#include <deque>

/* 핵심정리

1. 각각의 컨테이너가 독립적인 헤더파일 사용
2. 기본적인 사용법은 유사하다.
3. vector는 앞쪽으로 삽입/삭제 할 수 없다.
    → 연속된 메모리를 앞쪽에 삽입/삭제 하는 것은 성능이 좋지 않기 때문에 의도적인 설계
4. [ ] 연산은 vector, deque, array만 가능
    → random access iterator 또는 contiguous iterator를 가지는 컨테이너만 가능하다
    → list, forward_list는 사용할 수 없다.
5. 기본적인 사용법이 유사하므로 동일한 코드를 컨테이너 변경하면서 테스트 해볼 수 있다.

*/

int main()
{
	std::list   s{1,2,3,4,5};
	std::deque  d{1,2,3,4,5};
	std::vector v{1,2,3,4,5};

	// #1. 사용법이 유사하다.
	s.push_back(10);
	d.push_back(10);
	v.push_back(10);

	// #2. vector 는 앞쪽으로 삽입/삭제 할수 없다.
	s.push_front(10);
	d.push_front(10);
	v.push_front(10); // error

	// #3. [] 연산은 deque 와 vector 만 가능하다.
	s[0] = 10; 	// error
	d[0] = 10; 	// ok
	v[0] = 10; 	// ok
}