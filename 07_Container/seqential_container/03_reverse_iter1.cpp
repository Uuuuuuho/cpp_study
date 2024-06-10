#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  
  for(std::vector<int>::size_type i = vec.size()-1; i >= 0; i--)
    std::cout << vec[i] << std::endl;
    // "i--"는 -1이 아니라 해당 타입에서 가장 큰 정수를 빼기하게됨.
    // 따라서 런타임 오류.
  
  return 0;
}