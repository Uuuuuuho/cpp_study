#include <iostream>
#include <functional>
struct Point
{
  int x;
  int y;
};

int main()
{
  // p is a pointer-to-member-data: "int Point::*" means "pointer to an
  // int member of Point". It does not hold an absolute address; it must be
  // applied to an object (via .* or ->*) to access the actual member.
  int Point::*p = &Point::y;
  Point obj;

  // Access the member through an object using the .* operator:
  obj.*p = 10; // equivalent to obj.y = 10;
  // Or when you have a pointer to the object, use ->*:
  (&obj)->*p = 10; // also sets obj.y

  // std::invoke accepts a pointer-to-member-data and an object (or pointer)
  // and returns an lvalue reference to that member, so you can assign to it.
  std::invoke(p,obj) = 20; // sets obj.y to 20
  int n = std::invoke(p, obj); // reads obj.y

  std::cout << n << std::endl;
  std::cout << obj.y << std::endl;
}