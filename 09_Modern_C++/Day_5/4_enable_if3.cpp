#include <iostream>
#include <type_traits>

// std::enable_if<조건, T>::type 의 의미를 생각해 보세요
// 조건 true  : "::type" 은 T
// 조건 false : "::type" 이 없다

// 아래 코드는
// T가 정수라면 "반환 타입은 T"
// T가 정수 아니면 "반환 타입 만들기 실패" 
//  => SFINAE 에 따라 에러가 아니라 후보에서 제외

// 즉, T가 정수일때만 템플릿을 사용하겠다는 의미의 코드

template<typename T> 

typename std::enable_if< std::is_integral_v<T>, T>::type

gcd(T a, T b)
{
	std::cout << "T" << std::endl;
	return 0; .
}




double gcd(double a, double b)
{
	std::cout << "double" << std::endl;
	return 0;
}
int main()
{
	gcd(6, 9);
	gcd(3.1, 5.4);
	gcd(3.1f, 5.4f);
}