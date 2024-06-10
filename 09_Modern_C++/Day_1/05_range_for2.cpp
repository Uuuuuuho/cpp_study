// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	for (auto& n : v) 
	{
		std::cout << n << std::endl;
	}

    /* Compiler translate the code above into below */
    auto first = std::begin(v);
    auto last = std::end(v);

    /* Then, for statement. */
    for(; first != last; ++first)
    {
        auto& n = *first;
    }
}