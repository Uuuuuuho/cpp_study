#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <execution>
#include <mutex>
#include <chrono>
using namespace std::literals;

int main()
{
    std::vector<int> v(100, 0);

    for (int i = 1; i <= 100; i++)
        v.push_back(i);

    int sum = 0;

    // std::for_each(v.begin(), v.end(), [&](int n) { sum += n;});

    // 아래 코드는 여러개 스레드가 sum 공유함. 동기화 필요
    std::for_each(std::execution::par, v.begin(), v.end(), [&](int n) { sum += n;});

    // 해결책 1. mutex sync
    std::mutex mtx;
    std::for_each(std::execution::par, v.begin(), v.end(), [&](int n) { 
                                                std::lock_guard<std::mutex> g(mtx);
                                                sum += n;
                                                });
    
    // 해결책 2. sum 변수를 atomic으로
    std::atomic<int> sum2 = 0;
    std::for_each(std::execution::par, v.begin(), v.end(),
                        [&](int n){sum2+=n;})

    
    std::cout << sum << '\n';
}