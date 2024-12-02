#include <iostream>

template <typename T, T N>
struct integral_constant {

    static constexpr T value = N;
    using value_type = T;
    using type = integral_constant;
    constexpr operator value_type() const noexcept   { return value; }
    constexpr value_type operator()() const noexcept { return value; }
};

/* std::true_type, std::false_type
 * => true와 false를 가지고 만든 타입
 * true/false는 "참/거짓"을 나타내는 "값"인데 반해
 * std::true_type/false_type은 "참/거짓"을 나타내는 "타입"이다. (서로 다른 타입)
 */
using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

/* value_type을 상속받도록 구현함.
 * meta programming으로 인해 is_pointer와 is_pointer<T*>의 매핑이
 * true_type/false_type으로 지정됨.
 * 이러한 방식은 C++ 표준에 아래의 방식으로 구현되어있음.
 */
template<typename T> struct is_pointer      : false_type{}; // value = false
template<typename T> struct is_pointer<T*>  : true_type{};

void fn(true_type)  { std::cout << "true" << std::endl; }
void fn(false_type) { std::cout << "false" << std::endl; }

int main() {

    fn(is_pointer<int>());
    fn(is_pointer<int*>());
}