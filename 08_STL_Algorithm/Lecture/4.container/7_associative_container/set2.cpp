#include <set>
#include <print>

/* 
    std::set iterator
    → 반복자를 통해서 요소를 변경할 수 없다. (읽기만 가능함)
*/

int main()
{
	std::set s{ 50, 30, 70, 40, 60, 20, 80};

	auto p1 = s.begin();
	auto p2 = s.end();

//	*p1 = 75;	  // error
	int n1 = *p1; // ok

	while( p1 != p2 )
		std::println("{}", *p1++);

}