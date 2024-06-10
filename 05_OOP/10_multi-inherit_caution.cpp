#include <iostream>

class A{
public:
  int a;
  A(){ std::cout << "A constructor" << std::endl;}
};
class B{
public:
  int a;
  B(){ std::cout << "B constructor" << std::endl;}
};
class C : public A, public B{
public:
  int c;
  C() : A(), B() { std::cout << "C constructor" << std::endl;}
};

int main()
{
  C c;
  c.a = 0;  // ambiguous member access
}