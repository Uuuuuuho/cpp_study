#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

/* 핵심 개념
    1. advance 함수
        <iterator> 헤더가 필요함
        반복자를 N만큼 전진(후진) 하는 함수
*/

template<typename T>
void eadvance(T& p, int n){
    // p = p + 5; // list는 random access category에 포함되지 않음
    while(n--) 
        p++;      // 이렇게 만들면 vector는 성능저하가 발생함
                  // 컨테이너 종류에 따라 다르게 만들어야함
}

int main(){
    list<int> s = {1,2,3,4,5,6,7,8,9,10};

    auto p = begin(s);

    // 반복자 p를 5칸 전진하고 싶다.
    p = p + 5;
    // advance(p, 5); // STL
    // eadvance(p, 5);

    cout << *p << endl;
}