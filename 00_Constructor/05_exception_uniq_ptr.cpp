#include <iostream>
#include <memory>

struct Resource
{
  /* data */
  Resource()    {std::cout << "acquire Resource" << std::endl;}
  ~Resource()   {std::cout << "release Resource" << std::endl;}
};

class Test
{
private:
  /* data */
  // Use unique_ptr to manage the resource. If the constructor throws after
  // allocation, unique_ptr's automatic cleanup will prevent leaks because
  // the temporary owning object will be destroyed.
  std::unique_ptr<Resource> p;
public:
  // Prefer std::make_unique<Resource>() to avoid explicit 'new'. Even when
  // an exception is thrown later in the constructor, the unique_ptr will
  // ensure Resource is freed.
  Test(/* args */): p(std::make_unique<Resource>()){
    std::cout << "Test()" << std::endl;
    throw 1; // resource will be released by unique_ptr
  }
  ~Test(){
    // no manual delete needed: unique_ptr automatically deletes the resource
    // when Test is destroyed (if it was fully constructed).
    std::cout << "~Test()" << std::endl;
  }
};

int main(){
  try
  {
    Test t;
  }
  catch(const std::exception& e)
  {
    // std::cout << "exception occured" << std::endl;
    std::cerr << e.what() << '\n';
  }
  
}