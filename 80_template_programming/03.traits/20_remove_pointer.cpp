#include <iostream>
#include <type_traits>

/* 핵심 정리
 * T가 포인터인지 조사하는 방법
 * C++11 => std::is_pointer<T>::value
 * C++17 => std::is_pointer_v<T>
 * 
 * variable template 예시
 *  template <typename T>
 *  cosntexpr bool is_pointer_v = std::is_pointer<T>::value;
 * 
 * T에서 포인터를 제거한 타입 구하기
 * C++11 => typename std::remove_pointer<T>::type
 * C++14 => std::remove_poitner_T<T>
 * 
 * using template 예시
 *  template <typename T>
 *  using remove-pointer_t = typename std::remove_pointer<T>::type;
 */

template <typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;

template <typename T>
void fn(const T& arg) {

    // typename std::remove_pointer<T>::type n; // 너무 길게 작성됨
    // remove_pointer_t<T> n; // 위에서 remove_poiter_t를 정의함.
    std::remove_pointer_t<T> n; // C++14부터 정의함.

    std::cout << typeid(n).name() << std::endl;

}

int main() {

    int n = 10;
    fn(&n);
    fn(n);
}