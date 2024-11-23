#include <iostream>

template<typename T>
T square(T a) {
    std::cout << "T" << std::endl;
    return a * a;
}

/* 동일한 타입으로 정의하더라도 컴파일 단계에서 함수에 대해 서로 다른 ID를 부여하므로 서로 다른 함수임. */
int squre(int a) {
    std::cout << "int" << std::endl;
    return a * a;
}

int main() {
    /* 동일한 이름의 함수와 함수 템플릿을 만들 수 있다.
     * caller           callee
     * square(3)        square(3)
     * square<>(3)      square(T)
     * square(3.4)      square(T)
     * square<int>(3)   square(T)
     */
    square(3);
    square(3.4);

    square<int>(3);
    square<>(3);
}