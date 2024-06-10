#include <iostream>

struct A
{
  int x;
  void fa() { std::cout << this << std::endl; }
};
struct B
{
  int y;
  void fb() { std::cout << this << std::endl; }
};
struct C : public A, public B
{
  int z;
  void fc() { std::cout << this << std::endl; }
};

int main()
{
  C cc;

  void(C::*f)();
  
  std::cout << sizeof(f) << std::endl;  // 16B. 
                                        // 다중상속을 사용하는 클래스의 멤버 함수 포인터.
  // f = &C::fa;
  f = &C::fb;

  (cc.*f)(); // f.함수주소(&cc + f.this_offset)

  // void* p = f; // error
}