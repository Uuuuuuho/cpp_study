//8_nullptr3
#include <iostream>

int main()
{
	// 모든 리터럴에는 타입이 있습니다.
	3;		// int
	3.4;	// double
	false;	// bool 타입의 literal, 키워드
	nullptr;// std::nullptr_t	   키워드
			// std::nullptr_t 타입은 모든 포인터로
			// 암시적 변환된다는 문법이 있습니다.

	std::nullptr_t a = nullptr;

	int* p1 = a; // a는 결국 nullptr
}
// std::nullptr_t 타입에는 그럼 nullptr만 올수있나요?
// => 네..!!!
// => 물론 obj.operator nullptr_t() 가 있는 타입은 가능.