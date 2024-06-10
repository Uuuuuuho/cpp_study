#include <iostream>
#include <functional>

int main()
{
  int v1 = 10;

  // 핵심 1. reference_wrapper는 결국 객체(변수)의 주소를 보관함.
  std::reference_wrapper<int> r1(v1);

  // 핵심 2. reference_wrapper는 "raw reference"로 변환됩니다.
  // 이 특징 때문에 "raw pointer"보다 활용도가 높습니다.
  int &r2 = r1.get();
  int &r3 = r1;
}