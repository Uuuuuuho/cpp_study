#include <iostream>
#include <type_traits>

int main()
{
	int n = 10;
	
	// lvalue ? rvalue 조사하는 법
	// => "n+n" 이 rvalue 인지 lvalue 인지 알고 싶다.

	bool b1 = std::is_lvalue_reference< decltype(( n + n )) >::value;
	bool b2 = std::is_lvalue_reference_v< decltype((n + n)) >; // C++17

	if (std::is_lvalue_reference <  decltype((n + n)) >::value)
	{
		std::cout << "lvalue" << std::endl;
	}
	else	std::cout << "rvalue" << std::endl;
}
