#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m)
{
  for(const auto& kv : m) // kv has key & value
    std::cout << kv.first << " " << kv.second << std::endl;
}

int main() {
  std::map<std::string, double> pitcher_list;

  // 맵의 insert 함수는 std::pair 객체를 인자로 받습니다.
  pitcher_list.insert(std::pair<std::string, double>("A", 2.23));
  pitcher_list.insert(std::pair<std::string, double>("A", 2.93));

  print_map(pitcher_list);

  // 2.23 이 나올까 2.93 이 나올까?
  std::cout << "A score ? :: " << pitcher_list["A"] << std::endl;
}