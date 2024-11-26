#include <iostream.

/* printv 함수 템플랫
 * 인자로 전달된 변수의 값을 출력하는 함수(디버깅용)
 * 인자의 타입이 포인터면 구수값(메모리 주소)와 메모리에 있는 값(*value)"도 출력
 */
template <typename T> struct is_pointer     { enum value = false; }
template <typename T> struct is_pointer<T*> { enum value = true;  }

template <typename T>
void printv(const T& value) {
    if(is_pointer<T>::value)
        std::cout << value << " : " << *value << std::endl;
    else
        std::cout << value << std::endl;
}

int main() {
    int n = 10;
    printv(&n);
    printv(n); // printfv에서 "*value"가 컴파일 과정에서 dereference를 할 수 없다는 에러가 발생함.
    /* 해결방법
     * 1. std::integral_consant (int32type) C++11
     * 2. std::enable_if                    C++11
     * 3. if constexpr                      C++17
     * 4. concept                           C++20
     */
}