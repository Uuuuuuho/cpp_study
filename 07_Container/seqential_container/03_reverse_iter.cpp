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

  std::cout << "reverse vector print out" << std::endl;
  std::vector<int>::reverse_iterator r_iter = vec.rbegin();
  for(;r_iter!=vec.rend();r_iter++)
    std::cout << *r_iter << std::endl;
    
}