#include <iostream>

template <int N> struct int2type {
    enum { value = N };
};


/* int2type
 * => "int" 타입의 상수를 타입으로 만드는 도구
 * => int 뿐만 아니라 다른 "정수형타입의 상수(bool,
 *    char, short, long 등)도 타입"으로 만들면 좋지 않을까?
 * => std::integral_constant (C++11 표준)이 in2type의 발전된 형태 
 */
// "모든 정수형 타입의 상수"를 타입화
template <typename T, T N> struct integra_constant {
    static constexpr T value = N;
};

int main() {
    int2type<0> t1;
    int2type<1> t1;

    integra_constant<int, 0> n0;
    integra_constant<int, 1> n1;
    integra_constant<short, 1> n2;
    integra_constant<bool, true> n3;
}