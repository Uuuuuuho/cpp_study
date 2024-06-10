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

  X obj;
  // obj.f2(10); // error. f2라는 멤버를 찾게 됨.

  // pointer to member op 사용.
  // obj.*f2(10); // error. 연산자 우선순위를 문제.
  (obj.*f2)(10); // ok
}