#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/* reverse_iterator를 만드는 방법
    기존 방복자를 가지고 생성
        reverse_iterator<> 클래스 사용
        make_reverse_iterator<> 함수 사용
    컨테이너에서 직접 꺼내기
        rbegin(), rend() 멤버 함수

*/

int main()
{
    list<int> s = {1,2,3,4,5,5,6,7,8,9,10};

    auto ret = find(rbegin(s), rend(s), 3);

    auto p1 = begin(s);
    auto p2 = end(s);

    reverse_iterator<list<int>::iterator> r1(p2);
    auto r2 = make_reverse_iterator(p2);

    // reverse_iterator<list<int>::iterator>
    auto r3 = s.rbegin();
    auto r4 = rbegin(s);

    cout <<*r1 << endl;
    cout <<*r2 << endl;
    cout <<*r3 << endl;
    cout <<*r4 << endl;
}