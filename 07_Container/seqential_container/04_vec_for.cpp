#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  for(int ele: vec) std::cout << "element : " << ele << std::endl;

  return 0;
}
