#include <iostream>
/* C++20부터 적용되는 내용 */
#include <concepts>
/* template에서 typename의 종류에 따라 동작을 다르게 해야하는 경우 (template specialization) */
template<typename T> requires std::integral<T>
T square(T a) {
    std::cout << "integra" << std::endl;
    return a * a;
}

template<typename T> requires (!std::integral<T>) 
T square(T a) {
    std::cout << "not itnegra" << std::endl;
    return a * a;
}