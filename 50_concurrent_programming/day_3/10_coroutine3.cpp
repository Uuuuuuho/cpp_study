#include <iostream>
#include <coroutine>

/*  step 2. 코루틴 규칙
    1. "promise_type"이라는 타입을 가진 객체를 반환해야합니다.

    2. 아래 코드도 에러입니다.
       이 함수는 코루틴일 수 없습니다.
       "Generator::promise_type"은(는) 클래스가 아닙니다.
*/

class Generator
{
private:
  /* data */
public:
  using promise_type = int;
  Generator(/* args */);
  ~Generator();
  Generator foo()
  {
    std::cout << "foo 1" << std::endl;

    co_await std::suspend_always(); // suspend_always 타입의 임시객체생성
    std::cout << "foo 2" << std::endl;
  }
};

Generator::Generator(/* args */)
{
}

Generator::~Generator()
{
}


int main()
{
	foo();
}
