#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end)
{
  while (begin != end){
    std::cout << "[ " << *begin << "] ";
    begin++;
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> vec;
  vec.push_back(5);
  vec.push_back(3);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  std::cout << "initial vec" << std::endl;
  print(vec.begin(), vec.end());
  std::cout << "erase 3 from the vector" << std::endl;
  // 'std::remove'는 '3'을 끝으로 계속해서 shifting
  // 'std::vector.erase()'가 first argument iterator부터 second arg iterator까지 원소를 삭제.
  vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
  print(vec.begin(), vec.end());
}