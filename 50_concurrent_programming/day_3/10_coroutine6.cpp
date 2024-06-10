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
	std::suspend_always initial_suspend() 
	{
		std::cout << "initial_suspend" << std::endl;
		return {};
	}
	std::suspend_always final_suspend() noexcept { return {}; }
	Generator get_return_object() { return Generator(); };
	void unhandled_exception() {}
	void return_void() {}
};

Generator foo()
{
	//=====================================
	// C++ 컴파일러가 코루틴(co_로 시작하는 키워드를 사용한 함수)의 앞부분에 아래코드를 생성
	// 1. 힙에 메모리를 할당(모든 지역변수, promise_type 객체의 크기, 기타 정보) 보관
	
	// 2. Generator 안에 있는 promise_type의 위 힙안에 객체만들고, 생성자 호출

	// 3. promise_type 안에 get_return_object()함수 호출해서 Generator 객체 생성
	// 4. promise_type 안에 initial_update() 호출..
	//			=> 만든 경우만 호출.

	// 5. 3에서 만든 generator 반환.. 즉 여기서 바로 main 복귀.. 



	//=====================================
	std::cout << "foo 1" << std::endl;

	co_await std::suspend_always();

	std::cout << "foo 2" << std::endl;
}

int main()
{
	Generator g = foo();

	std::cout << "continue main" << std::endl;
}