#include <iostream>
#include <string>

template <typename T>
T max(T& a, T& b) {
    return a > b ? a : b;
}

int main() {

    /* 
     * Class tempalte과 달리 type argument를 template으로 전달하지 않음.
     * Compiler가 smart해서 필요가 없어짐.
     */
    int a = 1, b = 2;
    std::cout << "Max (" << a << "," << b << ") ? : " << max(a, b) << std::endl;

    std::string s = "hello", t = "world";
    std::cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << std::endl;
}