#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template <typename T, 
        template <typename, typename> class C = std::vector, // STL에서는 std::deqeue가 default template임.
        typename Ax = std::allocator<T> >
/* template 인자로 첫번째는 typename을 두번째는 type 인자가 2개인 template을 넘겨줘  */
class stack {
    C<T, Ax > c;
public:
    void push(const T& value)   { c.push_back(value); }
    void pop()                  { c.pop_back();       }
    T&   top()                  { return c.back();    }
};

int main() {
    // std::vector는 template paramter가 2개인 template임. 2번째 type이 default type이기 때문에 일반적으로 작성하지 않는 것.
    // stack<int, std::vector > s1;
    // stack<int, std::list> s1;
    stack<int> s1;
    s1.push(10);

}