#include <iostream>
#include <functional>

void foo(int& r)
{
	r = 200;
}

// parameter로 받은 "arg"를 foo 함수에 전달하는 함수
// 핵심은 "parameter arg"를 call by value로 하고 있다는 점.
// call by reference로 하면 되지만, 여러가지 이유로 call by value로 설계했다고 가정.
template<typename T> 
void forward_parameter_to_foo(T arg)
{
	foo(arg);
	std::cout << arg << std::endl;
}

int main()
{
	int n = 10;
	int *pn = &n;

	forward_parameter_to_foo(n);
	// forward_parameter_to_foo(&n); // reference conversion fail... build fail...
	// forward_parameter_to_foo(pn); // reference conversion fail... build fail...
	// forward_parameter_to_foo(*&n); // build succeeded, but value not changed.
	// std::reference_wrapper<int> r(n);
	// forward_parameter_to_foo(r);

	std::cout << n << std::endl;
}

