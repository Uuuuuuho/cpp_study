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
  Resource *p;
public:
  Test(/* args */): p(0){
    // 예외 가능성이 있는 어떠한 작업도 하지 않음.
  }
  void Construct(){
    p = new Resource;
    // 생성자가 아니므로 이 함수 안에서는 가상함수도 호출할 수 있음.
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
    t.Construct();
  }
  catch(const std::exception& e)
  {
    // std::cout << "exception occured" << std::endl;
    std::cerr << e.what() << '\n';
  }
  
}