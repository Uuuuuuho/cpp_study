#include <vector>
#include <algorithm>
#include "../cmc.h"

/* 
| 일반함수 |  |
| 함수 객체 | “operator() 멤버 함수를 제공”해서 함수처럼 사용 가능한 객체 |
| 람다표현식 | 함수 객체를 만드는 표현식 |
→ 일반 함수보다 “함수 객체 또는 람다표현식”을 사용하는 것을 권장함.

함수 객체, 람다표현식의 장점
→ 지역변수를 캡처할 수 있다.
→ 그 외에도 많은 장점이 있다.

*/

int main()
{
    std::vector<int> v1{1,2,3,4,5};
    std::vector<int> v2;

	// v1의 모든 요소에 main 의 지역변수 k를 더한 결과를
	// v2에 추가 하고 싶다. 
    int k = 2;

    std::ranges::transform(v1, std::back_inserter(v2), [k](int n){ return n + k; });

    show(v2);
}

// int add_k(int n){ return n + k; }