#include <iostream>
#include <chrono>

int main()
{
	std::chrono::seconds s(70);   // 70초

	std::chrono::milliseconds ms = s;	// ok	
										// 데이타 손실이 없으므로

	std::cout << ms.count() << std::endl; // 70000


	// std::chrono::minutes m = s; // error. 데이타 손실가능성이 있음

	std::chrono::minutes m =
		std::chrono::duration_cast<std::chrono::minutes>(s); // data loss 버림.

	std::cout << m.count() << std::endl;

}