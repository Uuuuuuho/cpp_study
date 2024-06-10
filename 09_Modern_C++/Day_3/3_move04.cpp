#include <iostream>
#include <string.h>
#include <cstring>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		std::strcpy(name, strlen(n)+1);
	}
	~Cat() { delete[] name; }

    Cat(const Cat& c) : age(c.age)
    {
        name = new char[strlen(c.name) + 1];
        std::strcpy(name, strlen(c.name) + 1, c.name);
    }
 
    /* 	Add copy constructor for temporary object. 
		a.k.a. move constructor
	*/
    Cat(Cat&& c) : age(c.age), name(c.name)
    {
		/*  To perform code below, it should be pointed to temp obj w/o const. */
		c.name = nullptr;
    }
};

Cat foo()
{
	Cat c("yaong", 3);
	return c;
}

int main()
{
	Cat c = foo(); 	/* Think about memory of this. 
						This will call "Cat(const Cat& c)".
						If user (deep) define copy constructor, it saves memory copy overhead.
					*/
}
