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
/* 주요 표준 attributes (간단히)
 * [[nodiscard]] — 반환값을 무시하지 않도록 컴파일러에 경고를 요청. (유용: error-prone한 반환값)
 * [[noreturn]] — 함수가 리턴하지 않음을 표시(예: 예외나 종료만 함).
 * [[maybe_unused]] — 변수/함수/형식이 사용되지 않아도 경고를 억제.
 * [[deprecated]] — 해당 엔티티가 폐기 예정임을 표시(옵션으로 메시지).
 * [[fallthrough]] — switch case에서 의도적 fall-through 표시(경고 억제).
 * [[no_unique_address]] — 멤버에 대해 빈 베이스 최적화 스타일의 공간 절약을 허용(C++20).
 * [[likely]] / [[unlikely]] — 분기 예측 힌트(표준화된 시점은 최신 표준 참조; 컴파일러별 차이 존재).
 * [[carries_dependency]] — 메모리 의존성 힌트(저수준 성능/병렬화 관련).
 * 구현/컴파일러 특화 네임스페이스: [[gnu::...]], [[clang::...]], [[msvc::...]] 등으로 특정 컴파일러 확장을 지정할 수 있음.
 */
[[nodiscard]] const T& max2(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}

int main(){
    max1(1,2);
    max2(1,2);
}