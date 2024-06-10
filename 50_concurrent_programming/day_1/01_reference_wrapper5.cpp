#include <iostream>
#include <functional>

void foo(int& r)	// reference parameter는 caller에서 pointer를 parameter로 지정해야만함.
{
	r = 200;
}

template<typename T> 
void forward_parameter_to_foo(T arg)
{
	foo(arg);
}

int main()
{
	int n = 10;

	// call by value로 설계된 라이브러리에 인자를 참조로 전달하고 싶다면,
	// 1. refererence_wrapper에 담아서 보내면 됨.
	std::reference_wrapper<int> r(n);

	forward_parameter_to_foo(r); // ok... n을 참조로 전달.

	// 2. std::ref()를 사용하면 "refrence_wrapper"를 편리하게 생성함.
	forward_parameter_to_foo(std::ref(n));
														// std::ref(n)
														// std::cref(n) - const reference를 의미함.

	std::cout << n << std::endl;
}

// std::reference_wrapper, std::ref() 는 언제 사용하나요 ?
// 1. 멀티 스레드 라이브러리에서 인자를 참조로 보내고 싶을때
// 2. std::bind() 에서 인자를 참조로 고정할때
// 3. C++20 range 라이브러리에서.. 