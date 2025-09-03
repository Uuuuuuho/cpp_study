#include <iostream>

struct Point
{
  int x;
  int y;
};

int main()
{
  int num = 0;

  int* p1 = &num;
  // p1: ordinary pointer to an int variable (holds an address)
  // p2: pointer-to-member-data. Its type is "int Point::*" meaning
  // "pointer to an int member of Point". It does NOT hold an absolute
  // address; it encodes how to find the member inside a Point object
  // (usually an offset). You cannot dereference p2 directly because
  // it needs an object to operate on.
  int Point::*p2 = &Point::y;

  *p1 = 10; // ok
  // *p2 = 10; // error: you can't dereference a pointer-to-member without
  // an object. p2 is not an int*; it's an offset-like member pointer.

  Point pt;
  // To access the member through a pointer-to-member, bind it to an
  // object (or pointer to object):
  pt.*p2 = 10;  // equivalent to pt.y = 10
                // Internally it acts like: *((char*)&pt + offset_of(y)) = 10
                // but you must not compute offsets manually — use the language
                // operators (.* / ->*) to be portable and correct.
  // Note: printing a pointer-to-member is not portable. It is not the same
  // as an object pointer (void*). Some compilers may allow reinterpreting
  // the value for debugging, but portable code should not assume it can be
  // printed as an address.
  // std::cout << p2 << std::endl; // typically ill-formed: no operator<< overload
  // printf("%p\n", p2);         // undefined/implementation-defined
}