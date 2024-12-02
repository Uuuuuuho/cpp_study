#include <type_traits>

/* 핵심 정리
 * T가 포인터인지 조사하는 방법
 *  C++11 => std::is_pointer<T>::value
 *  C++17 => std::is_pointer_v<T>
 * 
 * T의 포인터 여부에 따라 다른 구현을 작성하려면
 * 1. if constexpr로 조사후 작성 (C++17)
 * 2. std::true_type, std::false_type (C++11)로 함수 오버로딩
 * 3. std::enable_if (C++11)
 * 4. concept (C++20)
 */

template <typename T>
void fn_imp(const T& value, std::true_type) {}

template <typename T>
void fn_imp(const T& value, std::false_type) {}

template <typename T>
void fn(const T& value) {
    // 1. if cosntexpr (C++17부터 적용) => C++17이 적용 가능한 환경만
    if constexpr ( std::is_pointer_v<T> ){

    }
    else {

    }
    // 2. std::true/false_type을 인자로 받아서 오버로딩 하는 방법
    fn_imp(value, std::is_poiter<T>());
}

int main() {
    int n = 0;
    fn(n);
}