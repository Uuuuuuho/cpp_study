#include <iostream>
#include <string>

class Base{
  std::string s;

public:
  Base() : s("Base"){ std::cout << "Base Class" << std::endl; }
  void what(){ std::cout << s << std::endl; }
  ~Base(){ std::cout << "~Base()" << std::endl; }
};

class Derived : public Base { // this is upcasting
  std::string s;
public:
  Derived() : s("Derived"), Base() {std::cout << "Derived Class" << std::endl; }
  void what(){ std::cout << s << std::endl; }
  ~Derived(){ std::cout << "~Derived()" << std::endl; }
};

int main()
{
  Base p;
  Derived c;
  
  std::cout << "=== Pointer Version ===" << std::endl;
  Base* p_p = &c;

  Derived* p_c = dynamic_cast<Derived*>(p_p); // this causes compiler error
  p_c->what();
  return 0;
}