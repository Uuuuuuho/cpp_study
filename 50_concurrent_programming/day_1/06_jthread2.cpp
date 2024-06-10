#include <iostream>
#include <thread>

// join_thread 
// 28 page


void foo(int a, int b)
{
	std::cout << "foo : " << a << ", " << b << std::endl;
}

// 자동으로 join 하는 클래스 - 아주 널리 사용되던 기법
class scoped_thread
{
	std::thread impl;
public:
	scoped_thread(std::thread t) : impl(std::move(t)) {}

	~scoped_thread()
	{
		if (impl.joinable())
			impl.join();
	}
};
class join_thread
{
	std::thread impl;
public:
	template<typename T, typename ... Types>
	join_thread(T&& func, Types&& ... args) 
		: impl(std::forward<T>(func), std::forward<Types>(args)...) 
	{
	}
	~join_thread()
	{
		if (impl.joinable())
			impl.join();
	}
};
int main()
{
	// 1. std::thread 사용시 - 직접 join 해야 합니다.
	std::thread t1(&foo, 10, 20);
	t1.join();

	// 2. scoped_thread 사용시 - 자동 join  됩니다.
	// => std::thread 의 임시객체를 생성자로 전달
	scoped_thread st(std::thread(&foo, 10, 20));

	// 3. join_thread 사용시 - 자동 join 됩니다.
	// => std::thread 와 사용법은 동일
	join_thread jt(&foo, 10, 20); // std::thread 와 동일한 사용법

}