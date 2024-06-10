#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& s)
{
  std::cout << "[ ";
  for(typename std::set<T>::iterator iter = s.begin(); iter != s.end(); ++iter)
    std::cout << *iter << " ";
  std::cout << "] " << std::endl;
}

int main()
{
  std::set<int> s;
  s.insert(10);
  s.insert(20);
  s.insert(30);
  s.insert(20);
  s.insert(10);

  print_set(s);
}