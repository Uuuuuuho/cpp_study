#include <stack>
#include <queue>
#include <print>

/* 핵심정리
    std::stack, std::queue

    | header | <stack> | <queue> |
    | ---    | ---     | ---     |
    | insert | push()  | push()  |
    | remove | pop()   | pop()   |
    | access | top()   | front() |

    → STL 대부분의 멤버함수는 제거와 반환을 동시에 하지는 않는다.

*/

int main()
{
	std::stack<int> s;
	std::queue<int> q;

	// # 요소 넣기
	s.push(10); 
	s.push(20);
	q.push(10);	
	q.push(20);

	// # 요소 얻기
	std::println("{}", s.top());   // 20
	std::println("{}", q.front()); // 10

	// # 요소 제거
	s.pop();
	q.pop();
}