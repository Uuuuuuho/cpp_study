#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	std::vector<int> v3(10, 2); /* 
                                    vector(int, int) constructor.
                                    Init 10 elements as 2.
                                */
	std::vector<int> v4{10, 2}; /* 
                                    vector(std::initializer_list)
                                    Init 2 elements as 10.
                                */

    std::cout << v3.size() << std::endl;    /* 10 */
    std::cout << v4.size() << std::endl;    /* 2 */

	// std::vector<int> v5 = 10;	/* Error, which means this is "explicit vector(int)" */
	std::vector<int> v6 = {10}; /* 
                                    Ok.
                                    "vector(std::initialier_list)"
                                    is not explicit.
                                */
}




