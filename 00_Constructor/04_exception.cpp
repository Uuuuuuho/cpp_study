#include <iostream>
// This file demonstrates what happens when a constructor throws
// after acquiring a resource with a raw pointer.
//
// Key points:
// - If a constructor throws an exception, the object's destructor is NOT
//   called because the object was never fully constructed.
// - Any resources acquired (e.g. with `new`) before the throw must be
//   released by the constructor itself or, better, managed with RAII.
// - Using raw pointers as members and throwing in the constructor leads
//   to resource leaks. Use `std::unique_ptr` (or other RAII types) instead.

struct Resource
{
  // Simulate acquisition/release side effects
  Resource()    {std::cout << "acquire Resource" << std::endl;}
  ~Resource()   {std::cout << "release Resource" << std::endl;}
};

class Test
{
private:
  // BAD: raw pointer member. If the constructor throws after allocating `p`,
  //      the destructor is not run and `p` is leaked.
  Resource *p;
public:
  Test(/* args */): p(new Resource){
    std::cout << "Test()" << std::endl;
    // throw simulates a failure during construction
    throw 1;
  }
  ~Test(){
    // This destructor would free p, but it is NOT called if the constructor
    // throws. Therefore, p will leak in that scenario.
    delete p;
    std::cout << "~Test()" << std::endl;
  }
};

int main(){
  try
  {
    Test t; // allocation happens, then constructor throws -> leak occurs
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  // Safer alternative (recommended): manage the resource with RAII. Example:
  // {
  //   std::unique_ptr<Resource> p = std::make_unique<Resource>();
  //   // if an exception occurs here, p will be automatically released.
  // }
}