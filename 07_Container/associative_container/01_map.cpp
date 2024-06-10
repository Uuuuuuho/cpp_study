#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m)
{
  for(auto iter = m.begin(); iter != m.end(); ++iter)
    std::cout << iter->first << " " << iter->second << std::endl;
}

int main() {
  std::map<std::string, double> pitcher_list;

  // 참고로 2017년 7월 4일 현재 투수 방어율 순위입니다.

  // 맵의 insert 함수는 pair 객체를 인자로 받습니다.
  pitcher_list.insert(std::pair<std::string, double>("A", 2.23));
  pitcher_list.insert(std::pair<std::string, double>("B ", 2.93));

  pitcher_list.insert(std::pair<std::string, double>("C ", 2.95));

  // 타입을 지정하지 않아도 간단히 std::make_pair 함수로
  // std::pair 객체를 만들 수 도 있습니다.
  pitcher_list.insert(std::make_pair("D", 3.04));
  pitcher_list.insert(std::make_pair("E ", 3.05));
  pitcher_list.insert(std::make_pair("F ", 3.09));

  // 혹은 insert 를 안쓰더라도 [] 로 바로
  // 원소를 추가할 수 있습니다.
  pitcher_list["G"] = 3.56;
  pitcher_list["H"] = 3.76;
  pitcher_list["I"] = 3.90;

  print_map(pitcher_list);

  std::cout << "A score? :: " << pitcher_list["A"] << std::endl;
}