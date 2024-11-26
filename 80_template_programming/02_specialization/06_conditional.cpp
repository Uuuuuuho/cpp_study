#include <iostream>
#include <type_traits>

// primary template를 이용한 compile error detection
template <bool, typename T1, typename T2> struct conditional;
template <typename T1, typename T2> struct conditional<true, T1, T2> {
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