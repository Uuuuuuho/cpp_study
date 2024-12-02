#include <print>
#include <concepts>
#include <type_traits>

void foo(...) { std::println("..."); }

template <typename T>
// 이 위치는 리턴 타입을 결정짓는 자리임
// 아래에서 조건에 해당하는 부분은 "std::is_integral_v<T>"임
// 의미는 "T"가 integral이면 리턴 타입을 "void"를 "type"으로 지정하겠다는 의미입니다.
// 하지만 조건이 false이면, "void" 타입은 ::type 멤버가 없음. => SFINAE (후보에서 제외됨)
// typename std::enable_if<std::is_integral_v<T>, void>::type

// C++20 표준
std::enable_if_t< std::is_integral_v<T> >
foo(T a) {
    std::pritnln("T");
}

int main() {
    foo(3);     // T
    foo(3.4);   // ...
}
