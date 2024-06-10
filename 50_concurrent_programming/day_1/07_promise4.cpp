#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>

// 3번작업을 수행할 스레드 함수
void work(std::promise<int>& pro, std::vector<int>& v2)
{
    // 작업 3. v2의 모든 요소의 합 구하기
    int s = std::accumulate(v2.begin(), v2.end(), 0);

    pro.set_value(s);

    //... 마무리 작업이 있으면 수행...
}
int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> v2(10);

    // 작업 1. v1의 부분합을 구해서 v2에 넣기
    std::partial_sum(v1.begin(), v1.end(), v2.begin());

    std::promise<int> pro;
    std::future<int> ft = pro.get_future();

    // 작업3은 다른 스레드에게 작업 전달
    std::thread t(work, std::ref(pro), std::ref(v2));

    // 작업 2. v2 의 내용 출력
    for (auto n : v2)
        std::cout << n << ", ";
    
    // 작업4를 진행하려면 스레드의 결과를 대기 해야 한다.
    int s = ft.get();

    // 작업 4. 작업 3의 결과 출력
    std::cout << "\n" << s << std::endl;

    t.join();
}
