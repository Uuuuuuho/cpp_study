#include <iostream>
#include <vector>

template <typename T>
void print_vecotr(std::vector<T>& vec)
{
  for(typename std::vector<T>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    std::cout << *iter << std::endl;
}

int main()
{
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);
  vec.push_back(20);

  std::cout << "Initial vector state" << std::endl;
  print_vecotr(vec);
  std::cout << "==================" << std::endl;

  std::vector<int>::iterator iter = vec.begin();
  std::vector<int>::iterator end_iter = vec.end();
  
  for(; iter != end_iter; ++iter)
    if(*iter == 20) vec.erase(iter);
    // iterator를 erase하고나면, iterator 재사용은 안됨.
  
  std::cout << "value 20 erased" << std::endl;
  print_vecotr(vec);
}