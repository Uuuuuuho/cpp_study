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

    acc1.mtx.lock();
    std::this_thread::sleep_for(100ms); // deadlock을 만들기 위한 의도적인 코드
    acc2.mtx.lock();
    
    acc1.money -= cnt;
    acc2.money += cnt;
    std::cout << "finish transfer" << std::endl;
    
    acc1.mtx.unlock();
    acc2.mtx.unlock();
    
}


int main()
{
    Account kim, lee;
    std::thread t1(transfer, std::ref(kim), std::ref(lee), 5);
    std::thread t2(transfer, std::ref(lee), std::ref(kim), 5);
    t1.join();
    t2.join();
}

