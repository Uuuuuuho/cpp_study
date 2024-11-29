#include <iostream>
#include <type_traits>

/*
 * 템플릿 코드 작성시 타입 인자 "T가 포인터인 경우와 그렇지 않은 경우 각각 다르게
 * 작성"하고 싶다.
 * type traints 라이브러리
 * 1. 타입에 대한 다양한 속성을 조사하거나(query the properties of types)
 * 2. 변형(trnasformation) 된 타입을 구할 때 사용(type modifications)
 * C++1표에서 표준에 추가됨.

 * T가 포인터인지 조사하는 방법
 * C++11 => std::is_pointer<T>::value
 * C++17 => std::is_pointer_v<T>
 */
template <typename T>
void fn(const T& arg) {
    bool b1 = std::is_pointer<T>::value;
    bool b2 = std::is_pointer_v(T);

    /* T에서 포인터를 제거한 타입 구하기
     * c++11 => typename std::remove_pointer<T>::type
     * C++14 => std::remove_pointer_t<T>
     */
    typename std::remove_pointer<T>::type n1;
    std::remove_pointer_t<T> n2;

    /* type traits 역사
     * => 1990년대 말부터 도입된.
     * => boost 라이브러리에서 제공
     * => C++11에서 표준으로 도입
     */
}

int main() {
    int n = 0;
    fn(n);
    fn(&n);
}