#include <iostream>
#include <coroutine>
// step 1. 함수 안에서 co_wait, co_yield, co_return 중 한가지라도
//         사용하면 코루틴입니다.

void foo()
{
	std::cout << "foo 1" << std::endl;

  co_await std::suspend_always(); // suspend_always 타입의 임시객체생성
	std::cout << "foo 2" << std::endl;
}

int main()
{
	foo();
}
