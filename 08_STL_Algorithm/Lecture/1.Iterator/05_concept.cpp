#include <iostream>
#include <algorithm>
using namespace std;

/* 핵심 정리
    1. std::min
    2. 전달된 인자 중에서 작은값을 리턴하는 함수
    3. algorithm
    4. C++20부터
        특정 함수(클래스)를 사용하기 위해 타입이 가져야하는 조건
        min 함수에 전달되는 인자는 LessThanComparable을 만족해야한다.
        코드를 사용해서 concept를 정의할 수 있다.
    5. STL은 템플릿이지만 "모든 타입"에 적용되는 것이 아니라 "조건을 만족"하는 타입에 대해서 동작한다.    
*/

struct Point
{
    int x, y;
};

int main(){
    Point p1, p2;
    int n1 = min(1,2);
    // int n2 = min(1,2,3,4,5); // error

    int n2 = min({1,2,3,4,5}); // ok. initializer list
}