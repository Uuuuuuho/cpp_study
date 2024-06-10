#include <iostream>

template <typename... Ints>
int sum_all(Ints... nums)
{
  return (... + nums);  // C++ 17부터 도입된 "Fold" 형식
  // 기존 variadic template은 recursive call의 leaf function에서 
  // termination을 위한 function을 variadic template 이전에 정의해야함.
}

int main()
{
  std::cout << sum_all(1,4,2,3,10) << std::endl;
}