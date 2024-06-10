#include <vector>

class Car{};
std::vector<Car*> v;

void foo()
{
  Car* p1 = new Car;
  v.push_back(p1);
  // p1이 덩이상 피룡없다면 지워도 될까?
  /* 
      몇개의 참조가 사용되는지 개수를 관리해야함.
      Reference Counting
      C++뿐 아니라 다양한 언어에서 사용하는 일반적인 기술.
      Reference counting뿐 아니라 다양한 코딩기법 소개.
  */
  delete p1;
}

int main(){
  foo();
}