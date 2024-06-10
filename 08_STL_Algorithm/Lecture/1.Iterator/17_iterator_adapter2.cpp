#include <iostream>
#include <list>
#include <iterator>
using namespace std;

template<typename ITER> 
class Reverse_iterator
{
    ITER iter; // list의 일반 반복자. ++ =>
public:
    Reverse_iterator(ITER i) {iter = i; --iter;}

    Reverse_iterator& operator++() // 기존 container의 동작을 바꿔주기 위한 오버로딩
    {
        --iter;
        return *this;
    }

    typename ITER::value_type operator*()
    {
        return *iter;
    }
    //  ==, !=, --(++)
};

int main()
{
    list<int> s = {1,2,3,4,5,6,7,8,3,9,10};

    auto p1 = end(s);

    Reverse_iterator<list<int>::iterator> p2(p1);
    cout << *p2 << endl;
    ++p2;
    cout << *p2 << endl;
}