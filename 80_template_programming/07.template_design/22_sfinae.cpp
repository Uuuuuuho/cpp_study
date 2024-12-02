#include <iostream>

template <typename T>
void foo(T) {
    typename T::type n; // error
}

void foo(...) {
    std::cout << "..." << std::endl;
}

int main() {

    foo(3); // compile error
}

/* SFINAE 규칙은 아래의 3가지 경우에서 실패할 때 적용됨.
 * 1. function return type
 * 2. function parameter
 * 3. template parameter
 */