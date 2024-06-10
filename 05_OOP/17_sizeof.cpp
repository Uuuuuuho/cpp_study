#include <iostream>

// recursive call 종료를 위한 베이스 케이스
int sum_all(){ return 0; }

template <typename... Ints>
int sum_all(int num, Ints... nums)
{
  return num + sum_all(nums...);
}

template<typename... Ints>
double average(Ints... nums)
{   // "sizeof..."는 parameter pack의 개수를 리턴함.
    // "sizeof" primitive는 인자의 사이즈를 리턴하는 함수임.
  return static_cast<double>(sum_all(nums...))/sizeof...(nums);
}

int main()
{
  std::cout << average(1,4,2,3,10) << std::endl;
}