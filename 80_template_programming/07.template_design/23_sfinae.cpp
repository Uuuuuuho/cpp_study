#include <iostream>

void foo(...) { std::cout << "..." << std::endl; }

// #1. using return type
template<typename T> 
typename T::type foo(T a) {
    // return type이 int인 경우 실패
}

// #2. using parameter
template<typename T> 
void foo(T a, typename T::type  = 0 ) {
    // T가 int인 경우 치환 실패
}

// #3. using template parameter
template<typename T,
		 typename U = typename T::type> 
void foo(T a ) {
    // T가 int인 경우 치환 실패
}

template<typename T,
		 typename T::type = 0 > 
void foo(T a ) { }


int main()
{
	foo(3);
}