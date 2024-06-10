#include <iostream>

/*  Class
    C++98 : It should be done to make copy constructor, assign operator.
    C++11 : It's better to make move constructor and move operator.
    Users have to do these below since char* allocated and deallocated by user.
*/

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)      /* Constructor */
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }               /* Destructor */

	Cat(const Cat& c) : age(c.age)          /* User defined copy constructor */
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "copy ctor" << std::endl;
	}
	
	Cat(Cat&& c): age(c.age), name(c.name)  /* User defined move constructor */
	{
		c.name = nullptr;
		std::cout << "move ctor" << std::endl;
	}

	Cat& operator=(const Cat& c)            /* User defined assign operator */
	{
		if (&c == this) return *this;

		age = c.age;
		delete[] name;
		
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "copy assign(=) " << std::endl;

		return *this;
	}

	Cat& operator=(Cat&& c)                 /* User defined move operator */
	{
		if (&c == this) return *this;

		age = c.age;
		delete[] name;

		name = c.name;
		c.name = nullptr;	

		std::cout << "move assign(=) " << std::endl;
		return *this;
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




