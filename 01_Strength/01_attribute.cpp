#include <iostream>

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}
template<typename T>
[[nodiscard]] const T& max2(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}

int main(){
    max1(1,2);
    max2(1,2);
}