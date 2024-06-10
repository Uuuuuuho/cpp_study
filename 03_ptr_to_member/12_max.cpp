#include <iostream>
#include <string>

template<class T>
const T& max(const T& obj1, const T& obj2)
{
  return obj1 < obj2 ? obj2 : obj1;
}

int main()
{
  std::string s1 = "abcd";
  std::string s2 = "xyz";

  // auto ret1 = max(s1,s2);    // ambiguous error
  auto ret2 = max(s1.size(), s2.size());
}