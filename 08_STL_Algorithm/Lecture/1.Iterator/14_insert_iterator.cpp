#include <iostream>
#include <list>
#include <iterator>
using namespace std;

/* 핵심 정리
    1. 컨테이너 요소를 추가하는 방법
        - 멤버함수 사용(push_xxx/emplace_xxx/insert)
        삽입 반복자(insert iterator)
    2. 삽입 반복자
        - <iterator> 헤더
        - 컨테이너 요소를 삽입(추가)할 때 사용하는 방복자
        3가지 종류 (전방 삽입, 후방 삽입, 임의 삽입) 제공
    3. 기본 모양
        - back_insert_iterator<컨테이너 클래스 이름> p (컨테이너 객체);
    4. copy와 같은 STL 알고리즘을 사용해서 컨테이너에 요소를 추가할 수 있다.
*/

int main(int argc, char** argv)
{
    list<int> s = {1,2,3,4,5};

    s.push_back(10);

    back_insert_iterator<list<int>> p(s);

    *p = 20; // s.push_back(20);


    int x[5] = {1,2,3,4,5};
    // for(int i = 0; i < 5; i++)
    //     s.push_back(x[i]);

    copy(x, x+5, p);

    for (auto& n: s)
        cout << n << endl;
}