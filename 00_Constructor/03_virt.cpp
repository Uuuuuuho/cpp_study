#include <iostream>

class Base
{
private:
  /* data */
public:
  Base(/* args */)    {vfunc();}  
  void foo()          {vfunc();}
  virtual void vfunc(){std::cout << "Base vfunc" << std::endl;}
};

class Derived : public Base
{
private:
  /* data */
  int data{10};
public:
  virtual void vfunc() override{
    std::cout << "Derived vfunc : " << data << std::endl;
  }
};

int main(){
  Derived d;
  d.foo();
}