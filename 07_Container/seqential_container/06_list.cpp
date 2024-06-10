#include <iostream>
#include <list>

int main()
{
  std::list<int> lst;

  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  lst.push_back(40);

  for(std::list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++)
    std::cout << *iter << std::endl;
}