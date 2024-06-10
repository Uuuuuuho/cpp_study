#include <iostream>

int main()
{
	int x[3] = { 1,2,3 };

	// 아래 a1, a2 의 타입을 생각해 보세요
	
	auto  a1 = x;	// 1. int a1[3] = x; 로 결정하면 에러
					// 2. int* a1 = x; 로 결정하면 에러 아님.
					// => 2번이 답!!

	auto& a2 = x;	// int(&a2)[3] = x; 로 결정해도 에러아님
					// auto : int[3],  a2 : int(&)[3]
	
	// 결론 : auto 사용시 우변이 배열이면
	// auto = 배열 : auto 는 포인터
	// auto&= 배열 : auto 자체는 배열 타입

	// int(&a2)[3]  이 어려우신 분은 "배열을 가리키는 포인터"
	// int(*p2)[3]  을 학습해 보세요(C언어)

    std::cout << &x << " " << x[1] << " " <<  x+1 << std::endl;
    std::cout << &a1 << " " << a1[1] << " " <<  a1+1 << std::endl;
    std::cout << &a2 << " " << a2[1] << " " <<  a2+1 << std::endl;
}