#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    std::cout << *iter << std::endl;
  
  std::vector<int>::iterator iter = vec.begin() + 2;
  std::cout << "3th element : " << *iter << std::endl;
}