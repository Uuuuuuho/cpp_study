#include <iostream>

template<typename T>
[[nodiscard]] constexpr const T& max(const T& lhs, const T& rhs) noexcept(noexcept(lhs<rhs))
{
    return lhs < rhs ? rhs : lhs;
}

int main(){
    int ret = max(2,1); // compile time
    std::cout << ret << std::endl;
}