#include <iostream>

template<typename T>
T square(T a) {
    return a * a;
}

int main() {
    printf("%p\n", &square); // "square"는 함수가 아니라 함수 템플릿(틀)이다. square에 "typename"이 없이는 주소를 구할 수 없다.
    printf("%p\n", &square<int>);
    printf("%p\n", &square<double>);
}