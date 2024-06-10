// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	// std::list<int>   v = { 1,2,3,4,5 };
	// int v[5] = { 1,2,3,4,5 };

    /*  
        1. Should know the exact type.
            However, must modify below if the exact type is used.
        
            std::vector<int>::iterator p1 = v.begin();
            std::vector<int>::iterator p2 = v.end();
        
        2. Recommend to use 'auto'.

            auto p1 = v.begin(); // This is error if 'v' is raw array.

        3. Good flexibility for normal function with 'begin'.
    */

   auto p1 = std::begin(v); /* This does not cause error even if 'v' is raw array. */

//    auto sz = v.size(); /* Error if 'v' is raw array */
//    auto sz = std::size(v); /* Not error */
}