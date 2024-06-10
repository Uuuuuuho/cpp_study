#include <iostream>

class X
{
public:
  void mf1(int a){} // void mf1(X* this, int a){}
  static void mf2(int a){}
};
void foo(int a){}

int main()
{
  void(*f1)(int) = &foo;  // ok
  // void(*f2)(int) = &X::mf1; // error
  void(*f3)(int) = &X::mf2; // ok
}