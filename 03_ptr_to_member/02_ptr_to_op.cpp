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
  void(X::*f2)(int) = &X::mf1;  // ok

  f1(10); // ok. 일반함수 포인터로 함수 호출.
  // f2(10); // error. 객체가 필요함.
  // Explanation: `f2` is a pointer-to-member function. It does not store a
  // bound object; you must call it on an object (or pointer to object).
  // Syntax requires either (obj.*f2)(args) or (ptr->*f2)(args).

  X obj;
  // obj.f2(10); // error. f2라는 멤버를 찾게 됨.
  // Explanation: `obj.f2` would try to find a member named `f2` inside `obj`.
  // Pointer-to-member `f2` is a variable in the local scope, not a member of X.

  // pointer to member op 사용.
  // obj.*f2(10); // error. 연산자 우선순위 문제.
  // Explanation: `obj.*f2(10)` parses as `obj.*(f2(10))` because `()` binds
  // tighter than `.*`, so you must parenthesize the pointer-to-member access
  // first: `(obj.*f2)(10)` or use a pointer: `(ptr->*f2)(10)`.
  (obj.*f2)(10); // ok
}