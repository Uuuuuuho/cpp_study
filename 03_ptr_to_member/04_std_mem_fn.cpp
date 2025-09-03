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

  // std::mem_fn wraps a pointer-to-member into a callable object.
  // The resulting function object can be invoked with either an object
  // or a pointer to object as the first argument. It also adapts to
  // various callable contexts (e.g., std::bind, algorithms).
  auto f1 = std::mem_fn(&X::mf1);
  f1(obj, 10);   // calls obj.mf1(10)
  f1(&obj, 10);  // calls obj.mf1(10) as well (pointer accepted)
}