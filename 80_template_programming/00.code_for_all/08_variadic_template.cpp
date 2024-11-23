#include <iostream>

template <typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}

/* 
 * typename 뒤에 "..."로 오는 것을 parameter pack이라고 부름.
 * Parameter pack은 0개 이상의 템플릿 인자를 나타냄.
 * 마찬가지로 함수에 인자로 "..."이 오는 것을 
 * function parameter pack이라고 부름.
 * 아래 함수에서 Parameter pack은 컴파일타임에 재귀적으로
 * type inference가 이루어짐.
 * 다만, 위의 print 함수가 parameter pack funciton의 아래로 간다면
 * 컴파일 에러가 발생함. 이유는 C++ 컴파일러는 컴파일 시점을 기준으로
 * 앞쪽에 정의된 함수밖에 보지 못하기 때문임.
 */
template<typename T, typename ... Types>
void print(T arg, Types... args) {
    std::cout << arg << ", ";
    print(args...);
}

int main() {
    print(1, 3.1, "abc");
    print(1, 2, 3, 4, 5, 6, 7);
}