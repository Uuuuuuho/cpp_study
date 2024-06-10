#include <iostream>

class Point
{
  int x, y;
public:
  void set(int a, int b)  // void set(Point* const this, int a, int b)
  {
    x = a;    // this->x = a
    y = b;    // this->y = b
  }
  static void foo(int a)  // void foo(int a)
  {                       // {
    x = a;                // this->x = a;가 될 수 있어야함.
  }                       // 그런데 this가 없음.
                          // } 따라서 static member method는 일반 멤버에 접근 불가함.
};

int main()
{
  Point p1, p2;
  p1.set(10, 20); // set(&p1, 10, 20)의 방식으로 컴파일 됨.
                  // 일반적으로 함수 인자는 스택으로, 객체 주소는 레지스터로 전달됨.
                  // push 20
                  // push 10
                  // mov ecx, &p1
                  // call ?set@@xxxxx
  Point::foo(10); // static member method는 객체없이 호출 가능함.
                  // 그래서 전달할 객체가 없음.
}