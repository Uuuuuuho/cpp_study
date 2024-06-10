#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m)
{
  for(const auto& kv : m) // kv has key & value
    std::cout << kv.first << " " << kv.second << std::endl;
}
template <typename K, typename V>
void search_and_print(std::map<K,V>& m, K key)
{
  auto iter = m.find(key);
  if(iter != m.end()) std::cout << key << " --> " << iter->second << std::endl;
  else                std::cout << key << " is not in the list" << std::endl;
}

int main() {
  std::map<std::string, double> pitcher_list;

  pitcher_list["A"] = 3.58;

  print_map(pitcher_list);
  std::cout << "-----------------" << std::endl;

  search_and_print(pitcher_list, std::string("A"));
  search_and_print(pitcher_list, std::string("B"));
}