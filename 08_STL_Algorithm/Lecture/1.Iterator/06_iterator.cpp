#include <iostream>
#include <list>
using namespace std;

/* 핵심 정리
    1. 반복자 (GoF 디자인 패턴)
        복합 개체의 내부 구조에 상관없이 순차적으로 요소에 접근하기 위한 방법을 제공하는 것
    2. 반복자 in STL
        "반복자처럼 동작하는 모든 것은 반복자이다."
        ++ 연산자로 이동 가능하고, * 연산자로 요소에 접근 가능한 것
    3. 반복자의 다양한 형태
        Raw Pointer
        컨테이너 요소를 연거 위한 객체 (begin())
        스트림 반복자 (stream iterator)
        삽입 반복자 (insert iterator)
        ....
*/
int main(){
    int x[5] = {1,2,3,4,5};
    int* p = x;
    *p; ++p;
    list<int> s = {1,2,3,4,5};
    list<int>::iterator p2 = s.begin();
    cout << "*p2: " << *p2 << endl;
    *p2; ++p2;
}