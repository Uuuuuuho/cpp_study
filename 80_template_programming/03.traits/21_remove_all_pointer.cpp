#include <iostream>

template <typename T> struct remove_pointer {
    using type = T;
};

template <typename T> struct remove_pointer<T*> {
    // using type = T;
    using type = T;
};

// 아래와 같이 다중포인터 제거하는 specialization을 작성하면 끝도 없이 작성해야함.
// template <typename T> struct remove_pointer<T**> {
//     using type = T;
// };

template <typename T> struct remove_all_pointer {
    using type = T;
};

template <typename T> struct remove_all_pointer<T*> {
    // using type = T;
    using type = typename remove_all_pointer<T>::type; // recursive pointer removal
};

int main() {
    // std::cout << typeid(remove_pointer<int>::type).name() << std::endl;
    // std::cout << typeid(remove_pointer<int*>::type).name() << std::endl;
    // std::cout << typeid(remove_pointer<int**>::type).name() << std::endl;
    // std::cout << typeid(remove_pointer<int***>::type).name() << std::endl;

    std::cout << typeid(remove_all_pointer<int>::type).name() << std::endl;
    std::cout << typeid(remove_all_pointer<int*>::type).name() << std::endl;
    std::cout << typeid(remove_all_pointer<int**>::type).name() << std::endl;
    std::cout << typeid(remove_all_pointer<int***>::type).name() << std::endl;
}