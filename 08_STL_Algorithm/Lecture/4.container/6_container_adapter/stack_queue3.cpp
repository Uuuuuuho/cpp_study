#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>

/* 핵심 정리
    std::stack, std::queue의 내부 컨테이너 요구 조건
    stack
        container의 뒤쪽으로 삽입/삭제 3개의 멤버함수 필요
        - back()
        - push_back()
        - pop_back()
        std::list, std::vector, std::deque 사용 가능
    queue
        container의 뒤쪽으로 삽입, 앞에서 삭제 4개의 멤버 함수 필요
        - back()
        - front()
        - push_back()
        - pop_front()
            - std::vector에 없다.
        std::list, std::deque 사용 가능
*/

int main()
{
	// 다음중 잘못된 코드를 찾아 보세요
	std::stack<int, std::list<int>> s1;
	std::stack<int, std::deque<int>> s2;
	std::stack<int, std::vector<int>> s3;

	std::queue<int, std::list<int>> q1;
	std::queue<int, std::deque<int>> q2;
	std::queue<int, std::vector<int>> q3; // 잘못된 코드

	q3.push(10); // vector 의 push_back() 호출
	q3.pop();    // vector 의 pop_front() -> runtime error


}