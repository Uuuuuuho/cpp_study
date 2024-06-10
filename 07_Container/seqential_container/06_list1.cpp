#include <iostream>
#include <list>

template <typename T>
void print_list(std::list<T>& lst) {
  std::cout << "[ ";
  // 전체 리스트를 출력하기 (이 역시 범위 기반 for 문을 쓸 수 있습니다)
  for (const auto& elem : lst) {
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}
int main() {
  std::list<int> lst;

  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  lst.push_back(40);

  std::cout << "Initial list state " << std::endl;
  print_list(lst);

  for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
    // 만일 현재 원소가 20 이라면
    // 그 앞에 50 을 집어넣는다.
    if (*itr == 20) {
      lst.insert(itr, 50);
    }
  }

  std::cout << "insert 50 before 20 " << std::endl;
  print_list(lst);

  for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
    // 값이 30 인 원소를 삭제한다.
    if (*itr == 30) {
      lst.erase(itr);
      break;
    }
  }

  std::cout << "erase 30" << std::endl;
  print_list(lst);
}