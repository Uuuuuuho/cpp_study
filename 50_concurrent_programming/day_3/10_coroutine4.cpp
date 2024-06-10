#include <iostream>
#include <coroutine>

/*  step 3. promise_type은 반드시 클래스이여야하고,
            약속된 5개의 멤버함수가 있어야합니다.
            현재 코드는 약속된 5개 함수가 없습니다.
            에러입니다.
*/
class promise
{
private:
  /* data */
public:
  promise(/* args */);
  ~promise();
};

promise::promise(/* args */)
{
}

promise::~promise()
{
}

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
