#include <iostream>
#include <string>

/* 'String' move constructor */
/* Rule 1. When user doesn't provide constructor and move operator,
           Compier provide all.
           Auto generated copy function : Copy all members.
           Auto generated move function : Move by std::move() all members.
   
   Rule 2. When user provides only copy function,
           => Compiler does not provide move function.
           => std::move() calls user defined copy function.
           => If user wants move function to compiler, then user use "=default".
   
   Rule 3. When user provides only move functions,
           => Compiler removes copy functions.
           => User can use move by move functions,
              but user can't use copy by copy functions.
           => This can cause compile error since there is no copy function.
           => "=default" can be used in this case as well.
*/

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}


    /* When copy functions are only provided. */
    // Object(const Object& obj) : name(obj.name){
    //     std::cout << "User provides copy constructor" << std::endl;
    // }

    // /* Copy constructor exists above, but rest functions can be defined as below. */
    // Object(Object&&) = default;
    // Object& operator=(const Object&) = default;
    // Object& operator=(Object&&) = default;

    /* When move functions are only provided. */
    Object(Object&& obj) : name(std::move(obj.name))
    {
        std::cout << "User defined move constructor" << std::endl;
    }
};

int main()
{
	Object o1("obj1 to be or not to be");
	Object o2("obj2 to be or not to be");

	Object o3 = o1;                         /* Compiler provide copy constructor. */
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl;
	std::cout << o2.name << std::endl;  // ""
}