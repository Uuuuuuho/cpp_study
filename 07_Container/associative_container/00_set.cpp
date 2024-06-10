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
  s.insert(50);
  s.insert(20);
  s.insert(40);
  s.insert(30);

  std::cout << "ordered print out" << std::endl;
  print_set(s);

  std::cout << "is '20' an element of s? ";
  auto iter = s.find(20);
  if(iter != s.end()) std::cout << "Yes" << std::endl;
  else                std::cout << "No"  << std::endl;

  std::cout << "is '25' an element of s? ";
  iter = s.find(25);
  if(iter != s.end()) std::cout << "Yes" << std::endl;
  else                std::cout << "No"  << std::endl;

}