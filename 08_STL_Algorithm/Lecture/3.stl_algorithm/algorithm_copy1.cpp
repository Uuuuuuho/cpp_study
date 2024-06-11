#include <vector>
#include <algorithm>
#include "../cmc.h"

/* 
알고리즘의 복사 버전

→ 일부 알고리즘은 복사버전을 제공한다.

→ 알고리즘 이름이 “_copy”로 끝나는 알고리즘

→ 연산의 수행결과를 자신이 아닌 “다른 컨테이너에 저장”하는 알고리즘
*/

int main()
{
    std::vector v1{1,2,3,1,2,3,1,2,3,1,2,3,1};
    std::vector v2{0,0,0,0,0,0,0,0,0,0,0,0,0};

    // auto ret = std::ranges::remove(v1, 3);
    auto ret = std::ranges::remove_copy(v1, v2.begin(),3);

    show(v1);
    show(v2);
}