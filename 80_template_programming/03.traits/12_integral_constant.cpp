#include <iostream>
#include <type_traits>

template <typename T, T N>
struct integral_constant {

    static constexpr T value = N;
    using value_type = T;
    using type = integral_constant;
    constexpr operator value_type() const noexcept   { return value; }
    constexpr value_type operator()() const noexcept { return value; }
};

using true_type  = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

template<typename T> struct is_pointer      : false_type{}; // value = false
template<typename T> struct is_pointer<T*>  : true_type{};

template <typename T>
void printv_imp(const T& value, std::true_type) {
        std::cout << value << " : " << *value << std::endl;    
}

template <typename T>
void printv_imp(const T& value, std::false_type) {
    std::cout << value << std::endl;
}

template <typename T>
void printv(const T& value) {
    printv_imp(value, std::is_pointer<T>() );
}

int main() {

    printv(is_pointer<int>());
    printv(is_pointer<int*>());
}