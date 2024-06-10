#include <iostream>
#include <chrono>
using namespace std::literals;   // 30s, 30ms, 30min, 30ns 등
void sleep(std::chrono::seconds s) 
{
}

int main()
{
	// sleep에 인자를 전달하는 방법
	// 1. seconds 객체를 생성해서 전달
	std::chrono::seconds s(30);
	sleep(s);

	// 2. 임시객체 형태로 전달
	// => "클래스 이름(생성자인자)" 로 임시객체 생성
	sleep( std::chrono::seconds(30) ); 


	// 3. "user define literal" 문법으로 만든 "literal 접미사" 사용
	sleep( 30s ); // 이순간 컴파일러는
				  // 1. operator""s(30) 라는 함수를 찾게 됩니다.
				  // 2. C++표준에서 이미 아래처럼 만들어 놓았습니다
		// => std::chrono::seconds operator""s(   )
}