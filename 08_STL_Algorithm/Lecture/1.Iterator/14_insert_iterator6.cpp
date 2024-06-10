#include <list>
#include <iostream>
using namespace std;

/* 핵심 정리
    1. 모든 반복자는 *로 요소에 접근 가능하고 ++연산자로 이동 가능해야한다.
    2. 삽입 반복자의 연산
        연산    연산의 결과
        ++      no-op
        *       no-op
        =       container->push_back, push_front, insert
    3. Member type
        using iterator_category = output_iterator_tag;

        using value_type = void;
        using pointer = void;
        using reference = void;
        using difference_type = void;

        using container_type = C;
 */

template<typename C>
class eback_insert_iterator
{
    C* container;
public:
    /* g++ 내부에서 사용하는 type def */    
    using __iterator_category = output_iterator_tag;
    using value_type = void;
    using pointer = void;
    using reference = void;
    using difference_type = void;

    using container_type = C;

    eback_insert_iterator(C& c): container(addressof(c)) {} // c.operator&()
    // eback_insert_iterator(C& c): container(&c) {} // c.operator&()

    eback_insert_iterator& operator*() {return *this;}
    eback_insert_iterator& operator++() {return *this;}    // 전위형
    eback_insert_iterator& operator++(int) {return *this;} // 후위형
    eback_insert_iterator& operator=(const typename C::value_type& a)
    {
        container->push_back(a);
        return *this;
    }
    eback_insert_iterator& operator=(const typename C::value_type&& a)
    {
        container->push_back(move(a));
        return *this;
    }
};

int main()
{
    list<int> s = {1,2};
    eback_insert_iterator<list<int>> p(s);

    *p = 30; // (p.operator*()).operator=(30)
    int x[2] = {1,2};
    copy(x, x+2, p);

    for(auto& n:s)
        cout << n << endl;
}