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

  auto f1 = std::mem_fn(&X::mf1);
  f1(obj, 10);
  f1(&obj, 10);
}