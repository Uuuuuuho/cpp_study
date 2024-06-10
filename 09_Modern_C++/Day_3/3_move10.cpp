#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
    /* Move constructor recommendation 
       => Make sure no exception.
       => Notify it to compiler.
    */

	// Object(Object&&)
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{
	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10); // Think about this.

    Object o1;
    Object o2 = o1; /* copy constructor */
    Object o3 = std::move(o1); /* move constructor */
    Object o4 = std::move_if_noexcept(o2);  /* move when no except. */

	std::cout << "----------------" << std::endl;
}

