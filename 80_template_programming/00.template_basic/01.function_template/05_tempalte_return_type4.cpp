#include <iostream>
#include <type_traits>

template<typename T1, typename T2>
// T1과 T2의 공통의 data type을 return type으로 사용하겠다는 의미. 뒤에서 자세한 설명이 나옴.
typename std::common_type<T1, T2>::type add(const T1& a, const T2& b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4.3 ) << std::endl;
}