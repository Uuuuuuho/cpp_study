#include <iostream>

template<typename R, typename T1, typename T2>
R add(const T1& a, const T2& b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4.3) << std::endl; // return type inference가 안되므로 컴파일 에러
    std::cout << add<double, int, double>(3, 4.3) << std::endl;
    std::cout << add<double>(3, 4.3) << std::endl; // return type을 double로 지정.
}