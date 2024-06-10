#include <iostream>
#include <list>
#include <iterator>
using namespace std;

/*  1. 삽입 반복자의 종류
        클래스                  생성 함수               내부 구현 원리
        back_insert_iterator    back_inserter()         push_back()
        front_insert_iterator   front_inserter()        push_front()
        insert_iterator         inserter()              insert()
    2. 주의 사항
        vector는 앞에 삽입할 수 없다. (push_front 멤버함수가 없다.)
        임의 삽입의 경우 생성자 인자가 2개이다. (컨테이너와 삽입할 위치를 나타내는 반복자)
    3. 전방 삽입과 임의 삽입
        전방 삽입을 사용해서 컨테이너에 삽입하면 요소의 순서가 반대로 삽입되지만
        임의 삽입을 사용해서 컨테이너의 앞에 삽입하면 요소의 순서대로 삽입된다
*/

int main()
{
    int x[5] = {10,20,30,40,50};
    list<int> s = {1,2,3,4,5};

    // back_insert_iterator<list<int>> p(s);
    // front_insert_iterator<list<int>> p(s);

    // insert_iterator<list<int>> p(s, s.begin());

    // copy(x, x+5, p);
    // copy(x, x+5, back_inserter(s));
    // copy(x, x+5, front_inserter(s));
    copy(x, x+5, inserter(s, s.begin()));   // 컨테이너와 iterator에 대한 인자가 필요함

    for(auto& n: s)
        cout << n << endl;
}