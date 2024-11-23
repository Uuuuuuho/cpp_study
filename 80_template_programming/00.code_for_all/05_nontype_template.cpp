#include <iostream>

// 템플릿만 인자로 받을 수 있는 것은 아니다.
// num을 template으로 지정하지 않으면 컴파일 에러가 발생함.
template <typename T, int num>
T add_num(T t) {
    return t + num;
}

int main() {
    int x = 3;
    std::cout << "x : " << add_num<int, 5>(x) << std::endl;
}