#include <iostream>
#include <cstring>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, strlen(n) + 1);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, strlen(c.name) + 1);
		std::cout << "const lvalue reference move constructor is called" << std::endl;
	}

    /* This is move constructor */
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "move constructor" << std::endl;
	}
};
Cat foo()
{
	Cat c("yaong", 3);
	return c;
}
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;        /* Call copy constructor. */
	Cat c3 = foo();     /* Call move constructor. */
	Cat c4 = static_cast<Cat&&>(c2);    /* Cast lvalue to rvalue */
	Cat c5 = std::move(c3);             /* This works like 'static_cast<Cat&&>. */

    /*  std::move(c3) 
        => c3's resource goes to c5, but not destructs.    

        Conclusion
        1. std::move() does not move resource.
        2. std::move() does not only rvalue casting.
        3. 'static_cast' calls 'move constructor' in the Cat class.
    */
}

/* 
    Object obj1; 
    Object obj2 = std::move(obj1); // In this code.

    1. Use move constructor if the object has move constructor.
    2. Use copy constructor if the object doesn't have move constructor.

    i.e. for any types, it's able to use "std::move()".
    provided that it's error if there is no even copy constructor.
*/



