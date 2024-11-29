#include <iostream>

template <typename T> struct is_pointer     { enum {value = false}; };
template <typename T> struct is_pointer<T*> { enum {value = true} ; };

template <int N>
struct int2type {
    enum { value = N };
};

template <typename T>
void printv_imp(const T& value, int2type<1>) {
        std::cout << value << " : " << *value << std::endl;    
}

template <typename T>
void printv_imp(const T& value, int2type<0>) { // overloading 용도로만 사용해야하고, 인자를 전달하면 컴파일러 최적화가 잘 안됨.
    std::cout << value << std::endl;
}

template <typename T>
void printv(const T& value) {
    printv_imp(value, int2type< is_pointer<T>::value >() ); // int2type 객체가 되도록 ()을 삽입
}

int main() {
    int n = 10;
    printv(n);
    printv(&n);
}
