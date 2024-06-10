#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

constexpr std::size_t sz = 10000;
std::vector<int> v;

void init()
{
    for (int i = 0; i < sz; i++){
        v.push_back(i);
    }
}

// 구간의 합을 구하는 함수.
// [first,last)의 모든 요소의 합을 3번째 인자에 담는 함수
template<typename IT, typename RT> 
void sum(IT first, IT last, RT& result)
{
    result = std::accumulate(first, last, result);
}

int main()
{
    init();

    int s = 0;
    // sum(v.begin(), v.end(), s); // 주 스레드가 호출

    // 새로운 스레드로 sum 수행
    // std::thread t(sum, v.begin(), v.end(), std::ref(s));
                // error
                // sum을 직접 호출한 것이 아니므로 템플릿 인자 추론 안됨
    
    // std::thread t(sum<std::vector<int>::iterator, int>, v.begin(), v.end(), std::ref(s));
    std::thread t(sum<std::vector<int>::iterator, int>, v.begin(), v.end(), std::reference_wrapper<int>(s));

    t.join();

    std::cout << s << std::endl;
}
