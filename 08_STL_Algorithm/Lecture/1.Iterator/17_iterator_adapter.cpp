#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> s = {1,2,3,4,4,5,6,7,8,3,9,10};

    auto p1 = begin(s);
    auto p2 = end(s);

    reverse_iterator<list<int>::iterator> p3(p2); // p3와 p2는 다른 객체. 즉, 참조가 아님
    reverse_iterator<list<int>::iterator> p4(p1); // p4도 마찬가지

    ++p3; // --p2처럼 동작

    cout << *p3 << endl; // 10
    ++p3;
    cout << *p3 << endl; // 9
    ++p3;
    cout << *p3 << endl; // 3
    --p2;
    cout << *p2 << endl; // 10


    auto ret1 = find(p1, p2, 3); // 처음부터 끝까지
    auto ret2 = find(p3, p4, 3); // 끝부터 처음까지

    // auto ret = find(p1, p2, 3);
    // auto ret = find(p2, p1, 3); // error. p2는 list의 end()를 가리키고 find는 "--"가 아니라 "++" operator로 동작함
}