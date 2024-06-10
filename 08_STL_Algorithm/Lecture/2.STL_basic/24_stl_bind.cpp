#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/* std::bind
    modulus와 find_if
        modulus<>는 2항 함수 객체이다.
        find_if의 조건자는 단항이어야한다.
        이항을 단항으로 변경할 수 없을까?
*/

int main()
{
    modulus<int> m; // % 연산을 수행하는 함수 객체
    
    int n = m(10, 3); // 10 % 3 = 1

    int x[5] = {9,9,2,4,3};

    // 3의 배수가 아닌것을 찾고싶다

    find_if (x, x+5, m);
}