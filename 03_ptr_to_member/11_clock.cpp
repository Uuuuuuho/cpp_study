#include <iostream>
#include <string>
// #include "cppmaster.h"
#include <map>

class Clock
{
  static std::map<int, Clock*> this_map;
  std::string name;
public:
  Clock(const std::string& n) : name(n) {}

  void start(int ms, int id)
  {
    // int id = ec_set_timer(ms, timerHandler);
    this_map[id] = this;
  }
  // 핵심 1. 아래 함수는 반드시 static 멤버이여야 합니다.
  static void timerHandler(int id)
  {
    Clock* const self = this_map[id];
    // std::cout << name << std::endl;
    std::cout << self->name << std::endl;
  }
};
std::map<int, Clock*> Clock::this_map;

int main()
{
  Clock c1("A");
  Clock c2("\tB");
  c1.start(1000, 0);   // 1000ms당 이름 출력
  c2.start(500, 1);    // 500ms당 이름 출력
  // ec_process_message();
}
