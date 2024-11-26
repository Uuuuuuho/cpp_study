#include <iostream>

template<typename T> struct remove_pointer {
    static void print() {
        std::cout << typeid(T).name() << std::endl;
    }
};

// 포인터의 경우 부분 특수화
template<typename T> struct remove_pointer<T*> {
    static void print() {
        // "T"는 "int"이고 뒤에 "*"이 포인터임. 따라서 아래는 int를 출력하게됨.
        std::cout << typeid(T).name() << std::endl;
    }
};

int main() {
    remove_pointer<int>::print();
    remove_pointer<int*>::print();
}