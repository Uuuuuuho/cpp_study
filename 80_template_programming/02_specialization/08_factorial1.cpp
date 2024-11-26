#include <iostream>

template<std::size_t N> struct Factorial {
    enum { value = N * Factorial<N-1>::value };
};

template<> struct Factorial<1> {
    enum { value = 1 };
};

int main() {
    int ret = Factorial<5>::value;
              //        5 * F<4>::v
              //            4 * F<3>::v
              //            ...
              // Template Meta Programming: 컴파일타임에 연산을 수행하는 코드
              // C++11이 발표되기 전에 사용하던 기술
              // modern C++(C++11)이 발표된 이후부터 "constexpr 함수" 사용이 훨씬 보편화됨.
}