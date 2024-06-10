#include <iostream>
#include <iterator>
#include <forward_list>
using namespace std;

/* iterator 보조 함수
    next        반복자를 한 칸 전진
    prev        반복자를 한 칸 후진
    advance     반복자를 N만큼 이동
    distance    2개의 반복자의 차이
    iter_space  2개의 반복자가 가리키는 요소 교환
*/

int main() {
    int x[10] = {1,2,3,4,5,6,7,8,9,10};

    forward_list<int> s = {1,2,3,4,5,6,7,8,9,10};
    auto p1 = next(begin(s));   // list는 상관없어도 array는 필요함.
                                // C++은 l-value와 r-value를 구분하기 때문.
                                // r-value는 operator++()이 안됨.
    advance(p1, 3); // 덧셈이 되는 것은 forward iterator만 되기 때문
    cout << *p1 << endl;

    cout << distance(begin(s), p1) << endl; // p1 - begin(s)

    iter_swap(p1, begin(s));

    cout << *p1 << endl;
}