#include <iostream>

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
  Resource *p;
public:
  Test(/* args */): p(new Resource){
    std::cout << "Test()" << std::endl;
    throw 1;
  }
  ~Test(){
    delete p;
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
    std::cerr << e.what() << '\n';
  }
  
}