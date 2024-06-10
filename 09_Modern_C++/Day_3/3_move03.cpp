#include <iostream>
#include <string>
// shallow copy vs deep copy

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n)+1, n);
	}
	~Cat() { delete[] name; }

    /*  Do not use compiler copy constructor provided that class has pointer member. 
        User should provide copy constructor.
        => Deep copy constructor.
    */

   Cat(const Cat& c) : age(c.age)
   {
       name = new char[strlen(c.name) + 1];
       strcpy_s(name, strlen(c.name) + 1, c.name);
   }
};

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1; 
}

/*
Cat(const Cat& c) : age(c.age)
{
	name = new char[strlen(c.name) + 1];
	strcpy_s(name, strlen(c.name) + 1, c.name);
}
*/