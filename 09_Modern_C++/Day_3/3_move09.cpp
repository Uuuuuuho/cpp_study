#include <iostream>
#include <string>
/*  Class
    C++98 : It should be done to make copy constructor, assign operator.
    C++11 : It's better to make move constructor and move operator.
*/

class Cat
{
	// char* name;
	std::string name;
	int   age;
public:
	Cat(const std::string& n, int a) : name(n), age(a)      /* Constructor */
	{
	}
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;            /* Copy constructor */
	Cat c3 = std::move(c1); /* Move constructor */

	c3 = c2;                /* Call assign operator */
	c3 = std::move(c2);     /* Call move operator */
}




