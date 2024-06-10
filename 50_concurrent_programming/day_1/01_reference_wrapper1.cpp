#include <iostream>

// 4 page
// C++ 참조 : 이동 불가능한 참조, 한번 초기화 되면 다른 메모리를 가리킬수없다.
//			  대입 연산시, 참조의 이동이 아닌, 참조가 가리키는 값을 대입

// std::reference_wrapper : 이동 가능한 참조.
int main()
{
	int v1 = 10, v2 = 20;

//	int& r1 = v1;
//	int& r2 = v2;

	std::reference_wrapper<int> r1(v1); // 이동가능한 참조
	std::reference_wrapper<int> r2(v2); // C++11 에서 표준에 추가

	r1 = r2;	// 이 코드의 동작 방식을 생각해 봅시다.
				// 1. 참조의 이동	- reference_wrapper
				// 2. 참조가 가리키는 값의 대입 - C++ 참조

									// C++ 참조   std::reference_wrapper
	std::cout << v1 << std::endl;	// 20			10
	std::cout << v2 << std::endl;	// 20			20
	std::cout << r1 << std::endl;	// 20			20
	std::cout << r2 << std::endl;	// 20			20
}