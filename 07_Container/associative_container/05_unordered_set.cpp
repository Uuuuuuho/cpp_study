#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unordered_set(std::unordered_set<K>& us)
{
  for(const auto& ele : us) std::cout << ele << std::endl;
}

int main() {
  std::unordered_set<std::string> s;

  s.insert("hi");
  s.insert("my");
  s.insert("name");
  s.insert("is");
  s.insert("psi");
  s.insert("welcome");
  s.insert("to");
  s.insert("c++");

  print_unordered_set(s);
}