// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

    /* Introduced in C++11 */
	// for (int i = 0; i < v.size(); i++)
	for (auto e : v)    /* This is range for statement. */
	{
	}
}
