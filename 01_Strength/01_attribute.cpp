#include <iostream>

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}
template<typename T>
/* [[nodiscard]]는 C++17부터 적용되기 시작한 attribute입니다.
 * C++ 전역에서 사용이 가능하며 컴파일할때 특정 메시지를 생성하거나 컴파일러가 특정 동작을 수행할 수 있게 도와줍니다.
 * Attribute를 붙이는게 필수적인 것은 아닙니다. 다만 이를 통해 최적화 및 부가 동작을 수행할 수 있다는 점이 유의미합니다.
 * [[nodiscard]]는 컴파일러가 리턴값을 무시하지 않도록 컴파일러에게 알려줍니다.
 * 본 예시를 포함해서 디렉토리에 포함되어있는 예시들에서는 컴파일러의 도움을 받아서 최적화 할 수 있는 방법들을 소개하도록 하겠습니다.
 */
[[nodiscard]] const T& max2(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}

int main(){
    max1(1,2);
    max2(1,2);
}