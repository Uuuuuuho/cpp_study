#include <iostream>
#include <type_traits>

/* std::conditional<bool, Typ1, Type2>::type
 * 조건에 따라 타입을 선택하는 템플릿
 * <type_traits> header
 * 템플릿의 1번째 인자 (bool)에 따라 타입 선택
 * true => type = Type1;
 * false => type = Type2;
 */
template <bool, typename T1, typename T2> struct conditional {
    using type = T1;
}

// 첫번째 인자가 false이면 나를 써달라는 template
template <typename T1, typename T2> struct conditional<false, T1, T2> {
    using type = T2;
}

int main() {
    // std::conditional<true,  int, double>::type v1;
    // std::conditional<false, int, double>::type v2;

    // customized selective template
    conditional<true, int, double>::type v1;
    conditional<false, int, double>::type v2;
}