#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 람다 표현식
    C++11에서 추가된 문법
    익명의 함수 객체를 만드는 표현식
    "[]": 람다 표현식이 시작됨을 알리는 "lambda introducer"
*/

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    // 1. 일반 함수 전달
    for_each(begin(v), end(v), foo);

    // 2. 함수 객체를 전달
    for_each(begin(v), end(v), s);

    // 3. 람다표현식
    for_each(begin(v), end(v), [](int a){cout << a << endl;});
}