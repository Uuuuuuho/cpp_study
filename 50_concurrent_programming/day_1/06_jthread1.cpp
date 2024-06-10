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

int main()
{
	// std::thread 사용시 항상 "join", "detach"가 필요해서 불편합니다.
    std::thread t1(&foo, 10, 20);
	t1.join();

//	std::thread t2(&foo, 10, 20);
//	scoped_thread st1(t2);	// error. 입니다. thread 는 복사 될수없으므로
							// 좋은 특징 입니다.
							// 이 코드가 되면 t2.join() 을 하는 오류가 나올수
							// 있습니다.

	scoped_thread st2(std::thread(&foo, 10, 20)); // ok

	// st2가 파괴될때 자동으로 join()됩니다.
}