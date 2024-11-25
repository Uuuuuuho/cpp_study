/* C++ template의 종류
 * 1. function template
 * 2. class template
 * 3. variable template
 * 4. using template (template alias)
 */

#include <iostream>

// constexpr double pi = 3.141592;

/* variable template은 언제 사용하는가?
 * 주로 "tempalte specialization"과 같이 사용한다.
 * "type traits" 구현의 핵심 문법임.
 * 실제 STL의 구현에서 다양하게 활용되고 있다.
 */
template <typename T>
constexpr double pi = static_cast<T>(3.141592);

int main() {
    // double area = 3 * 3 * pi;
    double area1 = 3 * 3 * pi<double>; // static_cast<double>(3.141592)

    double area2 = 3 * 3 * pi<float>;
}   
