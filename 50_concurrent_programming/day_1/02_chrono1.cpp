#include <iostream>
#include <chrono>

// chrono 라이브러리 : 시간관련 라이브러리
// 14 page

int main()
{
//	std::chrono::seconds s1 = 30;	// error
	std::chrono::seconds s2(30);	// ok.. explicit 생성자. 

	std::chrono::nanoseconds ns(1);
	std::chrono::microseconds us(1);
	std::chrono::milliseconds ms(1);
	std::chrono::seconds ss(1);
	std::chrono::minutes m(1);
	std::chrono::hours   h(1);

	// C++20 : days, months, years 도 추가됩니다.
}