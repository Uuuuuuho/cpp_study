#include <iostream>
#include <concepts>
#include <type_traits>

void foo(...) { std::cout << "..." << std::endl; }

// template <typename T>
// void foo(T a) {
//     std::cout << "T" << std::endl;
// }

/* 정수인 경우만, 선별적으로 specialiazation을 적용하는 C++ 표준 */
template <typename T>
std::enable_if_t< std::is_integral_v<T> >
foo (T a) {
    std::cout << "T" << std::endl;
}

int main() {
    foo(3);     // T (template 버전)을 사용하게됨.
    foo(3.4);   // T
}

/* 함수 템플릿 foo를 정수 타입에 대해서만 사용하고 싶다.
 * => 단, 정수가 아닌 경우는 에러가 아닌 후보에서 제외하고 싶다.
 * C++20 => concetp 문법의 requires clauses 사용
 * ~C++17 => std::enable_if 기술 사용
 * 
 * std::enable_if를 이해하기 위해서는
 *  SFINAE 개념을 반드시 알고 있어야합니다.
 */