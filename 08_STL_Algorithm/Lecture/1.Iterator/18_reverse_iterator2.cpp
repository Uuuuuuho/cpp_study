#include <iostream>
#include <list>
#include <algorithm>
#include <forward_list>
using namespace std;

/* 컨테이너에서 꺼내는 iterator의 4가지 종류
    iterator
    areverse_iterator
    const_iterator
    const_reverse_iterator
*/

int main()
{
    list<int> s = {1,2,3,3,4,5,6,7,8,9,10};
    forward_list<int> s2 = {1,2,3,3,4,5,6,7,8,9,10};

    auto p5 = rbegin(s2); // 양방향 반복자 이상에서만 적용할 수 있습니다.

    // auto p1 = begin(s);

    list<int>::iterator p1 = begin(s);
    list<int>::reverse_iterator p2 = rbegin(s);
    list<int>::const_iterator p3 = cbegin(s);
    // *p3 = 10; // error

    list<int>::const_reverse_iterator p4 = crbegin(s);

    /* 위의 코드와 동일함 */
    // auto p1 = begin(s);
    // auto p2 = rbegin(s);
    // auto p3 = cbegin(s);
    // auto p4 = crbegin(s);
}