#include <iostream>
#include <coroutine>

// step 4. promise_type 에는 반드시 5개 함수가 있어야 합니다.

class promise;

class Generator
{
public:
	using promise_type = promise;
};

class promise
{
public:
	std::suspend_always initial_suspend() { return {}; }
	std::suspend_always final_suspend() noexcept { return {}; }
	Generator get_return_object() { return Generator; };
	void unhandled_exception() {}
	void return_void() {} 
};

Generator foo()
{
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always();

	std::cout << "foo 2" << std::endl;
}

int main()
{
	foo();

	std::cout << "continue main" << std::endl;
}