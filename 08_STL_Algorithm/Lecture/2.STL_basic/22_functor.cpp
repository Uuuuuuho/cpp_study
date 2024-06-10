#include <iostream>
using namespace std;

/* ()를 사용해서 호출하는 것들...
    1. 함수
    2. 함수 포인터
    3. ()를 재정의한 클래스
    4. 람다표현식

    함수객체
        최초에는 "() 연산자를 재정의해서 함수처럼 사용가능한 객체"라는 의미
        요즘에는 "() 연산자를 사용해서 함수처럼 호출 가능한 모든 객체"
            - 함수 포인터, ()를 재정의한 클래스, 멤버 함수 포인터 등...
    
    함수 객체의 장점
        알고리즘에 전달 시 일반 함수는 인라인 치환이 안되지만 함수객체는 인라인 치환 가능합니다.
        상태를 가질 수 있다.
*/

struct Plus
{
    int operator()(int a, int b) const{
        return a + b;
    }
};

int main()
{
    Plus p;
    int n = p(1,2);
    cout << n << endl;

    /* 
        a + b;   // a.operator+(b)
        a - b;   // a.operaotr-(b)
        a();     // a.operator()()
        a(1,2);  // a.operator()(1,2)
    */
}