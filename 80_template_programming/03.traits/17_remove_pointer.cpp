#include <iostream>
#include <type_traits>

/* type traits 라이브러리
 * 1. 타입에 대한 다양한 속성을 조사하거나
 *    (query the properties of types)
 * 2. 변형(transformation)된 타입을 구할때 사용
 *    (Type modification)
 */

template <typename T>
void fn (const T& value) {
    // T n;

    // std::remove_poitner_t<T> 여기가지가 포인터를 제거한 타입
    std::remove_pointer_t<T> n;

    std::cout << typeid(n).name() << std::endl;
}

int main() {
    int n = 0;
    fn(n);
    fn(&n);
}