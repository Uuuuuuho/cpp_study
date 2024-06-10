#include <iostream>
#include <list>
using namespace std;

/* 반복자 카테고리 관련 용어 정리
    1. 입력 vs. 출력
        입력: 반복자를 통해서 컨테이너 안의 요소를 읽는 것 (= *i) 
        <=> 출력
    2. "++" vs. "+"
        list: ++ 연산은 제공하지만 + 연산은 제공하지 않음
        vector: ++와 + 연산 모두 제공
        dequeue: ++와 + 연산 모두 제공
            ** "+" 연산이 제공되어도 반드시 연속된 메모리는 아님
*/
int main(){
    list<int> s1 = {1,2,3};

    auto i = begin(s1);
    int n = *i; // 입력

    *i = 20; // 출력

    ++i; // ok

    i = i + 2;
}