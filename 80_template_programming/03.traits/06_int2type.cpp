#include <iostream>

template <typename T> struct is_pointer     { enum {value = false}; };
template <typename T> struct is_pointer<T*> { enum {value = true} ; };

template <typename T>
void printv_imp(const T& value, YES) {
        std::cout << value << " : " << *value << std::endl;    
}

template <typename T>
void printv_imp(const T& value, NO) {
    std::cout << value << std::endl;
}

template <typename T>
void printv(const T& value) {
    /* 함수 오버로딩
     * 동일한 이름의 함수가 여러개 있을때 "어떤 함수를 호출할지 결정하는 것은
     * '컴파일 타임'에 결정"한다. 단, 인자의 타입이 다르거나 개수가 달라야한다.
     */
    // if (is_pointer<T>::value)
    //     pointer(value);
    // else
    //     not_pointer(value);
    printv_imp(value, is_pointer<T>::value);
                      // true => 1
                      // false => 0
}

int main() {
    int n = 10;
    printv(10);
}
