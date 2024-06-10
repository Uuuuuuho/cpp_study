#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

struct  Account
{
    std::mutex mtx;   // 계좌(money)에 접근하려면 이 뮤텍스를 획득후 접근해라
    int money = 100;
};

void transfer(Account& acc1, Account& acc2, int cnt)
{
  std::cout << "start transfer" << std::endl;

  // 방법 1. std::lock()으로 N개 뮤텍스 획득 후, lock_guard로 관리
  // std::lock(acc1.mtx, acc2.mtx);
  // std::lock_guard<std::mutex> g1(acc1.mtx, std::adopt_lock);
  // std::lock_guard<std::mutex> g2(acc2.mtx, std::adopt_lock);

  // 방법 2. 아래 한줄이 위 3줄과 동일
  // std::scoped_lock<std::mutex, std::mutex> g(acc1.mtx, acc2.mtx);

  // 방법 3. C++17부터는 "템플릿 인자 생략" 가능.
  std::scoped_lock g(acc1.mtx, acc2.mtx);

  acc1.money -= cnt;
  acc2.money += cnt;

  std::cout << "finish transfer" << std::endl;
}


int main()
{
    Account kim, lee;
    std::thread t1(transfer, std::ref(kim), std::ref(lee), 5);
    std::thread t2(transfer, std::ref(lee), std::ref(kim), 5);
    t1.join();
    t2.join();
}

/*  C++ 표준
    6개의 뮤텍스
    4개의 lock management
*/