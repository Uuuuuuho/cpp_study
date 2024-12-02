#include <iostream>
#include <type_traits>

// namespace mystd
// {
//     /* std에는 아래와 같이 template type에 대한 specialization이 이미 구현되어있지만
//      * custom으로 개발하는 경우 아래와 같이 type마다 specialization을 정의해야만 합니다.
//      */
//     template <typename T> struct is_pointer     : std::false_type {};
//     template <typename T> struct is_pointer<T*> : std::true_type  {};
//     template <typename T> struct is_pointer<T* const> : std::true_type  {};
//     template <typename T> struct is_pointer<T* volatile> : std::true_type  {};
//     template <typename T> struct is_pointer<T* const volatile> : std::true_type  {};
// } // namespace mystd

/* 구조적으로 효율적인 방법은 없을까? */
namespace mystd
{
    namespace detail
    {
    template <typename T> struct is_pointer     : std::false_type {};
    template <typename T> struct is_pointer<T*> : std::true_type  {};
    } // namespace detail

    template <typename T>
    // const, volatile을 제거한 타입을 "is_pointer"에 넘겨줘 (type modification)
    using is_pointer = detail::is_pointer< std::remove_cv_t<T> >;  
    
} // namespace mystd

int main() {
    // namespace X = std;
    namespace X = mystd;

    std::cout << X::is_pointer<int>::value                  << std::endl;
    std::cout << X::is_pointer<int*>::value                 << std::endl;
    std::cout << X::is_pointer<int* const>::value           << std::endl;
    std::cout << X::is_pointer<int* volatile>::value        << std::endl;
    std::cout << X::is_pointer<int* const volatile>::value  << std::endl;
}