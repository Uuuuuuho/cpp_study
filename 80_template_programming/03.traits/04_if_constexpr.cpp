#include <iostream>

template <typename T> struct is_pointer     { enum {value = false}; };
template <typename T> struct is_pointer<T*> { enum {value = true} ; };

template <typename T>
void printv(const T& value) {
    // if(is_pointer<T>::value)
    //     // 컴파일 타임에 false로 결정되었지만 코드가 인스턴스화 되는 과정에서 C++ 함수에 포함됨.
    //     std::cout << value << " : " << *value << std::endl;
    // 조건이 false인 경우 코드가 인스턴스화 된 함수에 포함되지 않음.
    // 즉, 
    // if constexpr(false) {}
    // else
    //  std::cout << value << std::endl;
    // 로 코드가 생성됨.
    if constexpr(is_pointer<T>::value)
        std::cout << value << " : " << *value << std::endl;    
    else
        std::cout << value << std::endl;
}

int main() {
    int n = 10;
    printv(&n);
    printv(n);
}