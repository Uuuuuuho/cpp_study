#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n1{ 0 };	/* Direct initialization  */
	int n2 = { 0 }; /* Copy initialization    */
	int n3;			/* Default initialization */
	int n4{};		/* 
                        Value initialization
                        => empty brace
                        => if int type, use '{0}'
                    */

	std::cout << n4 << std::endl; /* 0 */

	Point pt{}; /* Init with default values of every member. */
	std::cout << pt.x << std::endl;
}


