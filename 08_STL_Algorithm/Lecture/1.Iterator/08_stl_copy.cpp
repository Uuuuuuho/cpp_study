#include <iostream>
#include <list>
using namespace std;

/* 
    1. copy 알고리즘
        하나의 구간의 내용을 다른 구간으로 복사하는 알고리즘
        <algorithm>
        반복문의 일반화된 표현
        1번째 구간은 완전한 구간(first, last)가 전달되지만 2번째 구간은 시작만 전달된다.
        1번째 구간을 통해서 2번째 구간의 끝을 예측할 수 있다.
*/

int main(){
    int x[5] = {1,2,3,4,5};
    int y[5] = {0,0,0,0,0};

    list<int> s2 = {0,0,0,0,0};

    // for(int i = 0; i < 5; i++) y[i] = x[i]; // C 스타일

    // copy(x, x+5, y); // C++ 스타일
    copy(x, x+5, begin(s2)); // C++ 스타일

    for(auto& n:y) cout << n << ", ";

}