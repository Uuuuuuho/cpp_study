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
  
  // Size/representation note:
  // - A pointer-to-member-function is NOT the same as a regular function
  //   pointer. For simple single-inheritance classes it might be the size of
  //   a single pointer, but when multiple inheritance, virtual bases, or
  //   virtual functions are involved, the pointer-to-member must carry
  //   additional information (for example: a code pointer + a this-adjust
  //   offset or even a small thunk). Implementations commonly use a pair
  //   {func_ptr, this_adjustment} or similar, which explains the larger
  //   sizeof(f) (often 16 bytes on many ABIs).
  std::cout << sizeof(f) << std::endl;  // often > sizeof(void*) when MI is used

  // Picking a member: note that fa is declared in A, fb in B. A pointer-to-
  // member of C that refers to B::fb may need a different this-adjustment
  // than one that refers to A::fa because the A and B subobjects have
  // different offsets inside C.
  // f = &C::fa; // would also work, but the runtime thunk/adjustment differs
  f = &C::fb;

  // Call syntax: you must bind the pointer-to-member to an object (.* or ->*),
  // which performs the necessary this-adjustment and then jumps to the
  // actual function address. Conceptually: call_at( &cc + this_adjust, func_ptr ).
  (cc.*f)(); // invokes C::fb on cc (after adjusting `this` to point to B-subobject)

  // You cannot convert a pointer-to-member-function to void* or a plain
  // function pointer portably. Their representations are different and the
  // language does not allow such conversions:
  // void* p = f; // error (ill-formed)
}