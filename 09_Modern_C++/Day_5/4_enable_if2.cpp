#include <iostream>
#include <type_traits>

// static_assert : 조건을 만족하지 않으면 컴파일 중지!!
// 원하는 것       : 조건을 만족하지 않으면 템플릿 사용하지 않겠다..
//				    동일 이름의 다른 함수가 있으면 사용가능

// 정수의 최대 공약수 구하는 함수
template<typename T> T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>,
				"error T is not integer");

	return 0; // 구현생략..
}
double gcd(double a, double b)
{
	std::cout << "double" << std::endl;
	return 0;
}
int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);
	gcd(3.1f, 5.4f);
}