#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

/* Container 종류에 관계없이 동작하도록 wrapper class를 정의하려면
 * 다중 typename을 인자로 받아야함. 다만, default parameter를
 * 정의하는 편이 좋은 방향임.
 */
template <typename T, typename C = std::deque<T> > // default paramter를 사용할 수 있음.
class stack {
    C c;
public:
    void push(const T& value)   { c.push_back(value); }
    void pop()                  { c.pop_back();       }
    T&   top()                  { return c.back();    }
};

int main() {
    
    stack<int, std::list<int> > s1;
    stack<int, std::vector<int> > s2;
    std::stack<int, std::list<int> > s3; // std::stack은 위와 같이 구현되어있음.
    /* std::stack
     * Container adapter
     * 선형 컨테이너(vector, list, deque)의 멤버 함수이름을
     * stack처럼 사용할 수 있게 변경한 것.
     */
    s1.push(10);

}