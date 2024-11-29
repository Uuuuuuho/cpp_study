#include <iostream>

template <typename T> struct is_pointer     { enum {value = false}; };
template <typename T> struct is_pointer<T*> { enum {value = true} ; };

template <typename T>
void pointer(const T& value) {
        std::cout << value << " : " << *value << std::endl;    
}

template <typename T>
void not_pointer(const T& value) {
    std::cout << value << std::endl;
}

template <typename T>
void printv(const T& value) {
    /* C++17 이전에 어떠한 방식으로 구현되었는지 살펴보자.
     * 1. 포인터의 경우와 포인터가 아닌 경우를 별도의 함수 템플릿으로 분리하는 방법.
     * => "사용되지 않은 함수 테플릿은 인스턴스화 되지 않는다"는 예상
     * => 하지만, if문 사용시 컴파일 타임에 false로 결정되어도 "모두 사용되는 것으로
     *    간주해서 "pointer(), not_pointer()"를 모두 인스턴스화" 한다.
     *    따라서 이 방법은 실패!
     *    "constexpr" 사용하면 되지만 지금은 사용하지 않는 방법을 고민중이므로 패스..
     */

    if (is_pointer<T>::value)
        pointer(value);
    else
        not_pointer(value);
}

int main() {
    int n = 10;
    printv(10);
}
