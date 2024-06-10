#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::literals;

// 은행 계좌 입니다.
struct  Account
{
    std::mutex mtx;   // 계좌(money)에 접근하려면 이 뮤텍스를 획득후 접근해라
    int money = 100;
};

void transfer(Account& acc1, Account& acc2, int cnt)
{
    std::cout << "start transfer" << std::endl;

    // 2개 이상의 mutex 를 lock 하려면 직접 lock 하지말고
    // std::lock() 함수를 사용하세요, 
    // "deadlock" 회피 기술로 구현되어 있습니다

    std::lock(acc1.mtx, acc2.mtx);

    // 2개 mutex 를 이미 lock 했으므로, unlock 만 자동화 합니다
    std::lock_guard<std::mutex> g1(acc1.mtx, std::adopt_lock);
    std::lock_guard<std::mutex> g2(acc2.mtx, std::adopt_lock);


    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;

//  acc2.mtx.unlock();
//  acc1.mtx.unlock();
}





int main()
{
    Account kim, lee;
    std::thread t1(transfer, std::ref(kim), std::ref(lee), 5);
    std::thread t2(transfer, std::ref(lee), std::ref(kim), 5);
    t1.join();
    t2.join();
}