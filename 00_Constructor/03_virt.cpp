#include <iostream>

// When to use virtual functions:
// - Use virtual functions for runtime polymorphism: call through a base pointer/reference
//   and dispatch to the most-derived override.
// - Use them to define interfaces or extension points (for example, Shape::draw()).
// - If objects may be deleted via a base pointer, make the base destructor virtual.
// - Avoid calling virtual functions from constructors or destructors: during construction
//   and destruction the dynamic type is the current class being (de)constructed, so
//   overrides in more-derived classes will NOT be called.
// - Alternatives: templates/CRTP or std::variant/std::visit for compile-time polymorphism
//   or when you want to avoid vtable overhead.


class Base
{
private:
  /* data */
public:
  Base(/* args */)    {vfunc();}  
  // Note: inside a constructor (or destructor) virtual calls are
  // resolved to the type currently being constructed/destructed.
  // Here, during Base::Base(), the dynamic type is considered 'Base',
  // so this call will invoke Base::vfunc(), not any override in Derived.
  Base(/* args */)    {vfunc();}  

  // After the whole object is constructed, the dynamic type becomes
  // the most-derived type (Derived in our example). Calling foo() on
  // a Derived object dispatches virtually and thus calls Derived::vfunc().
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
  // 'data' is initialized before this point (Derived construction
  // finishes), so it's safe to use here. This override will be
  // called by virtual dispatch after construction completes.
  std::cout << "Derived vfunc : " << data << std::endl;
  }
};

int main(){
  Derived d;
  d.foo();
}