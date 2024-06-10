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

  std::cout << "Initial vector state" << std::endl;
  print_vecotr(vec);
  std::cout << "==================" << std::endl;

  vec.insert(vec.begin()+2, 15);
  print_vecotr(vec);
  std::cout << "==================" << std::endl;

  vec.erase(vec.begin() + 3);
  print_vecotr(vec);
}