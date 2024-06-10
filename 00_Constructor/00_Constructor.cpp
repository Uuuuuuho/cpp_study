#include <iostream>

struct BM
{
  BM()    {std::cout << "BM()" << std::endl;}
  ~BM()   {std::cout << "~BM()" << std::endl;}
};
struct DM
{
  DM()    {std::cout << "DM()" << std::endl;}
  DM(int) {std::cout << "DM()int" <<std::endl;}
  ~DM()   {std::cout << "~/DM()" << std::endl;}
};
struct Base
{
  BM bm;
  Base()      {std::cout << "Base()" << std::endl;}
  Base(int a) {std::cout << "Base(int a)" << std::endl;}
  ~Base()     {std::cout << "~Base()" << std::endl;}
};
struct Derived: public Base
{
  DM dm;
  Derived()       :Base(),dm()      {std::cout << "Derived()" << std::endl;}
  Derived(int a)  :Base(0),dm(0)    {std::cout << "Derived(int a)" << std::endl;}
  ~Derived()                        {std::cout << "~Derived()" << std::endl;}
};

int main(){
  Derived d1;
  // Derived d2(7);
}
