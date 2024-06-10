#include <iostream>
#include <list>
using namespace std;

/* 
    1. 반복자의 구간(range)
        [first, last): 시작과 마지막 다음 요소(past the end)를 가리키는 반복자의 쌍
        유효한(valid) 구간: first부터 시작해서 ++ 연산으로 last에 도달할 수 있는 구간
        빈(empty) 구간: first == last인 경우, 빈 구간도 유효한 구간이다.
*/
int main(){
    list<int> s1 = {1,2,3};
    list<int> s2 = {4,5,6};

    auto p1 = begin(s1);
    auto p2 = end(s1);
    while(p1 != p2){
        ++p1;
    }

    list<int> s3;
    if(s3.empty()){}
    if(begin(s3)==end(s3));


}