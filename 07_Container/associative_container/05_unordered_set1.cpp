#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unordered_set(std::unordered_set<K>& us)
{
  for(const auto& ele : us) std::cout << ele << std::endl;
}
template <typename K>
void is_exist(std::unordered_set<K>& s, K key)
{
  auto iter = s.find(key);
  if (iter != s.end())  std::cout << key << " does exist!" << std::endl;
  else                  std::cout << key << " does not exist" << std::endl;
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
  std::cout << "----------------" << std::endl;
  is_exist(s, std::string("c++"));
  is_exist(s, std::string("c"));

  std::cout << "----------------" << std::endl;
  std::cout << "delte 'hi'" << std::endl;
  s.erase(s.find("hi"));
  is_exist(s, std::string("hi"));
}