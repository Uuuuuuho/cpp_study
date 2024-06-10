#include <iostream>

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}
template<typename T>
[[nodiscard]] inline const T& max2(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}
template<typename T>
[[nodiscard]] constexpr const T& max3(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}

int main(){
    int ret1 = max1(1,2); // 호출. 최저고하에 따라 inline도 가능
    int ret2 = max2(1,2); // 치환
    int ret3 = max3(1,2); // compile time
}