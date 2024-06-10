#include <vector>
#include <algorithm>
#include <functional>
#include "../cmc.h"

/* 
sort 알고리즘

→ 기본적으로는 오름차순 정렬

→ 마지막 인자로 “이항 함수르 전달”하면 비교 정책을 변경할 수 있다.

람다 표현식

→ 함수 객체를 만드는 표현식

→ 람다 표현식을 사용하면 컴파일러가 “operator() 연산자 함수를 가진 클래스를 생성”하는 것.

→ C++ 표전에 다양한 기본 연산을 제공하는 함수객체가 이미 제공됨.
*/

int main()
{
    namespace rgs = std::ranges;

    std::vector v {1,3,5,7,9,2,4,6,8,10};

    rgs::sort(v); // increasing order
    show(v);

    // rgs::sort(v, [](int a, int b) { return a > b; }); // decreasing order
    // rgs::sort(v, std::greater<int>{});
    rgs::sort(v, std::greater{}); // ~ C++17

    rgs::sort(v, {}); // rgs::sort(v);
                      // rgs::sort(v, std::less{}); // SAME
    show(v);
}