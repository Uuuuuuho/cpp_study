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
struct is_odd{
  int num_delete;

  is_odd() : num_delete(0){}

  bool operator()(const int& i){
    if(num_delete >=2) return false;
    if(i%2==1){
      num_delete++;
      return true;
    }
    return false;
  }
};

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

  std::cout << "remove the first two odds" << std::endl;
  vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());  
  print(vec.begin(), vec.end());
}