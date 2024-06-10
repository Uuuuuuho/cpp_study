#include <tuple>
#include <iostream>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);
	
	std::cout << p.first  << std::endl; // 1
	std::cout << p.second << std::endl; // 2.3
	
	std::pair<int, std::pair<double, short>> p2(1, { 2.3, 5 });

	std::cout << p2.second.first << std::endl; // 2.3 나오게 해보세요

	// C++11 부터 갯수의 제한 없이 서로 다른 타입을 보관할수 있는
	// tuple 이 도입 되었습니다.
	std::tuple<int, char, double> t(1, 'A', 3.4);

	std::cout << std::get<2>(t) << std::endl; // 3.4
}
