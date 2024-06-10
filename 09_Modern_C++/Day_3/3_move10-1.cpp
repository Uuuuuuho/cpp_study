#include <iostream>
#include <vector>
#include <string>

template<typename T>
class Object
{
	T data;
	std::string name;
public:
	Object() {}
	Object(const Object& obj) 
		: name(obj.name), data(obj.data)
	{
		std::cout << "copy" << std::endl; 
	}



	/* Use 'noexcept' only when there is no exception. 
	   Find "std::string" in "cppreference.com".
	*/

	// f() noexcept;	   // 예외없음
	// f() noexcept(true); // 예외없음
	// f() noexcept(false); // 예외있음.

	Object(Object&& obj) 
		noexcept ( noexcept(data(std::move(obj.data)))   )
		: name( std::move(obj.name) ), data(std::move(obj.data))
	{
		std::cout << "move" << std::endl;
	}
};
