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

  std::vector<int>::iterator iter = vec.begin() +2;

  *iter = 50;

  std::cout << "==================" << std::endl;
  print_vecotr(vec);

  std::vector<int>::const_iterator citer = vec.cbegin() + 2;

  *citer = 30; // 이건 에러. constant iterator 값은 변경 불가능함.
}