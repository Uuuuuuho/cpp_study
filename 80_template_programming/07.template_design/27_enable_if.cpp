#include <iostream>
#include <concepts>
#include <type_traits>

void foo(...) { std::cout << "..." << std::endl; }

// C++20 표준
template <typename T>
std::enable_if_t< std::is_integral_v<T> >
printv(const T& value) {
    std::cout << "pointer" << std::endl;
}

template <typename T>
std::enable_if_t< !std::is_integral_v<T> >
printv(const T& value) {
    std::cout << "not pointer" << std::endl;
}

int main() {

    int n = 0;
    printv(n);  // not pointer
    printv(&n); // pointer
}

/* 정리 
 * std::enable_if_t를 사용해서 조건을 만족하는 경우만 
 * 사용할 함수 템플릿을 만드는 방법
 * => 반환 타입 위치에 std::enable_if_t 사용
 * 
 * 반환 타입이 void인 경우
 * template <typename T>
 * std::enable_if_t< 조건 > // 조건은 컴팡리 타임에 조사 간으한 표현식으로 작성해야합니다.
 * foo (T a)               // 대부분 type_traits 기술을 사용하게 됩니다.
 * {}
 * 
 * 반환 타입이 void가 아닌 경우
 * template <typename T>
 * std::enable_if_t< 조건, return_type >
 * foo(T a)
 * { return value; }
 */