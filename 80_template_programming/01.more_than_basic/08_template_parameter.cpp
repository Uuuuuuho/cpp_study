#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

/* STL의 sequence container
 * 인자가 2개인 template
 * template<class T, class Ax=std::allocator<T> > class vector;
 * template<class T, class Ax=std::allocator<T> > class list;
 * template<class T, class Ax=std::allocator<T> > class deque;
 */

template <typename T> class List {
    T tmp = 0;
public:
    void push_back(const T& a) {}
    void pop_back() {}
    T&   back() { return tmp; };
};

template <typename T, 
        template <typename> class C = std::deque> // type 1개짜리 template을 받도록 설정. deque가 type을 2개 받지만 2번째 type은 default로 설정되어있기 때문에 괜찮음.
class stack {
    // C<T, Ax > c;
    C<T> c;
public:
    void push(const T& value)   { c.push_back(value); }
    void pop()                  { c.pop_back();       }
    T&   top()                  { return c.back();    }
};

int main() {

    stack<int, List> s1;
    // stack<int, std::vector> s2;
    s1.push(10);
}