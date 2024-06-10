#include <functional>

class X
{
public:
  void mf1(int a){}
};
void foo(int a){}

int main()
{
  X obj;

  void(*f1)(int) = &foo;
  void(X::*f2)(int) = &X::mf1;

  // 함수를 호출하는 방법이 다름.
  f1(10);         // 일반 함수 포인터
  (obj.*f2)(10);  // 멤버 함수 포인터

  // std::invoke를 사용하면 동일한 형태가 됨.
  std::invoke(f1, 10);      // f1(10)
  std::invoke(f2, obj, 10);
  std::invoke(f2, &obj, 10);
}