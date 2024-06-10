#include <iostream>
#include <coroutine>

// step 4. promise_type 에는 반드시 5개 함수가 있어야 합니다.

class promise;

// Generator 의 용도
// => 코루틴 핸들을 멤버로 가지고 있다고, main 함수에서 사용할수 있게 하는 것
// => 핵심 : Generator 만들때 생성자 인자로 핸들을 보내서 초기화 해야 한다.
class Generator
{
public:
	using promise_type = promise;

	std::coroutine_handle<promise_type> chandle; // 코루틴 frame 를 가리키는 핸들
										// 힙에 생성된 메모리
										// 지역변수및 다양한 정보 관리

	Generator(std::coroutine_handle<promise_type> h) : chandle(h) {}
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
	
	
	Generator get_return_object() 
	{
		// 현재 코루틴을 위한 핸들 얻기
		auto handle = std::coroutine_handle<promise>::from_promise(*this);

		// Generator 만들때 코루틴 핸들을 전달합니다.
		return Generator(handle); 
	};



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

	co_await std::suspend_always();  // main 으로 다시 돌아가라는 의미.

	std::cout << "foo 2" << std::endl;
}

int main()
{
	Generator g = foo();

	std::cout << "continue main 1" << std::endl;

	g.chandle.resume(); // foo를 계속 실행되게 합니다. foo1 출력후
	std::cout << "continue main 2" << std::endl;
	g.chandle.resume();
}