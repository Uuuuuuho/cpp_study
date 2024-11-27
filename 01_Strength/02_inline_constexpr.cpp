#include <iostream>

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}
template<typename T>
/* inline 키워드는 아래의 함수를 caller에 직접 삽입하는 방식으로 procedure call overhead를 줄이기 위한 방법이에요.
 * 다만, inlining 최적화는 자주 호출되지만 함수의 내용이 적은 경우에 사용하는 최적화 기법입니다.
 * 함수의 내용이 너무 많으면 코드사이즈가 여기저기서 크게 작성되기 때문에 오히려 성능이 안좋아 질 수 있으니까요.
 */
inline const T& max2(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}
template<typename T>
/* constexpr 키워드는 객체나 함수 앞에 붙일 수 있는 키워드로 "해당 객체나 함수의 리턴값을 컴파일 타임에 알 수 있다"를 의미합니다.
 * 아래 예시는 리턴값은 없고 그 값을 컴파일타임에 구해서 caller의 return variable에 대입해주게 되는것이죠.
 */
constexpr const T& max3(const T& lhs, const T& rhs)
{
    return lhs < rhs ? rhs : lhs;
}

int main(){
    int ret1 = max1(1,2); // 호출. 최저고하에 따라 inline도 가능
    int ret2 = max2(1,2); // 치환
    int ret3 = max3(1,2); // compile time
}