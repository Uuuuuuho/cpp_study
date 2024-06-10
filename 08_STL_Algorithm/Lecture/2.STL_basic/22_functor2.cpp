#include <iostream>
#include <vector>
#include <functional> // template 버전으로 operator overloading을 지원합니다..
using namespace std;

/* <functional> header
    산술연산
        plus<>
        minus
        multiplies
        divides<>
        modulus
        negate
    비교연산
        equal_to
        not_equal_to
        greater
        less
        greater_equal
        less_equal
    논리연산
        logical_and
        logical_or
        logical_not
*/
struct Plus
{
    int operator()(int a, int b) const{
        return a + b;
    }
};

int main()
{
    plus<int> p;
    cout << p(1,2) << endl;

    multiplies<int> m;
    cout << m(3,4) << endl;
}