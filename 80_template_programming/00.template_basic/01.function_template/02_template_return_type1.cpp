#include <iostream>

template<typename T>
T add(const T& a, const T& b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4)          << std::endl;
    std::cout << add(3.1, 4.3)      << std::endl;

    std::cout << add(3, 4.3)        << std::endl; // type inference가 불가함.
    std::cout << add<double>(3, 4.3)<< std::endl; // 2개 다 double로 받도록 지정하지만, 서로다른 타입을 입력으로 사용하고 싶을 수 있음.
}