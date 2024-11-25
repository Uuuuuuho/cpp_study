#include <iostream>

template <typename T>
void fn(T a) { std::cout << "T" << std::endl; }

// 동일한 이름의 함수와 함수 템플릿이 있을때, "함수"가 우선적으로 선택된다.
// void fn(int n) { std::cout << "int" << std::endl; }
void fn(int n); // 선언만 있는 경우? 링크 에러가 발생함.
// 앞선 예시도 마찬가지로 friend 멤버함수가 필요한 타입의 함수는 선언만 있을뿐 구현체가 포함되지 않기 때문임..

int main() {
    fn(3);
}