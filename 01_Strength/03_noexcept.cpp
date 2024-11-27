#include <iostream>

template<typename T>
/* 예외를 방출하지 않을 함수는 "noexcept"로 선언해야합니다.
 * 이 키워드는 예외를 방지하기 위한 것인데, 컴파일타임에 키워드의 인자에 해당하는
 * 부분을 조사해서 예외가 발생하는지 사용자에게 알려주기 위한 것입니다.
 * 아래의 예시라면 컴파일 에러없이 빌드되는 것을 확인할 수 있을거에요.
 */
[[nodiscard]] constexpr const T& max(const T& lhs, const T& rhs) noexcept(noexcept(lhs<rhs))
{
    return lhs < rhs ? rhs : lhs;
}

int main(){
    int ret = max(2,1); // compile time
    std::cout << ret << std::endl;
}