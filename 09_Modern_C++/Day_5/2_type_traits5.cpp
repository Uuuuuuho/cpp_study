// 4_type_traits - 184page

#include <iostream>
#include <type_traits>

template<typename T> void printv(const T& v)
{
	// if (std::is_pointer_v<T>) /* Error since if 문을 런타임에 실행함. */
	if constexpr (std::is_pointer_v<T>)	/* constexpr는 compile time에 if문을 수행함. */
		std::cout << v << " : " << *v << std::endl;
	else 
		std::cout << v << std::endl;
}
int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}