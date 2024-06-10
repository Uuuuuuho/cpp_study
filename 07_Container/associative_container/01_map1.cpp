#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m)
{
  for(const auto& kv : m)
    std::cout << kv.first << " " << kv.second << std::endl;
}

int main() {
  std::map<std::string, double> pitcher_list;

  pitcher_list["A"] = 3.58;
  std::cout << "B score? :: " << pitcher_list["B"] << std::endl;
  // defulat constructor added for "B"

  std::cout << "======================" << std::endl;
  print_map(pitcher_list);
}