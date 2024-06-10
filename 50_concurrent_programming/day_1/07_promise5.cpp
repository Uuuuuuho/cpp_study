#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>

// 이번 예제 핵심 : "람다 표현식을 스레드 수행하는 모양 알아 두세요"
//                 main의 지역변수에 쉽게 접근한다는 장점이 있습니다.
//                 널리 사용되는 기술입니다..

// 특정 함수 안에서 하는 작업을 여러 스레드로 분리할때..
// 스레드를 "일반 함수"로 만들면, 많은 지역변수를 전달하는 경우가 있습니다.
// => 이 경우는 스레드 함수를 람다 표현식으로 만드는것이 편리합니다.

int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> v2(10);

    // 작업 1. v1의 부분합을 구해서 v2에 넣기
    std::partial_sum(v1.begin(), v1.end(), v2.begin());


    std::promise<int> pro;
    std::future<int> ft = pro.get_future();


    // 작업3은 다른 스레드에게... 람다표현식으로
//  std::thread t([&v2, &pro](){  
    std::thread t([&]() {   // 함수의 지역변수에 reference access 할 수 있음.
                            // 지역변수가 적은 경우는 기존 방식대로 해도 무방함.
        int s = std::accumulate(v2.begin(), v2.end(), 0);
        pro.set_value(s);        
        });


    // 작업 2. v2 의 내용 출력
    for (auto n : v2)
        std::cout << n << ", ";

    // 작업4를 진행하려면 스레드의 결과를 대기 해야 한다.
    int s = ft.get();

    // 작업 4. 작업 3의 결과 출력
    std::cout << "\n" << s << std::endl;

    t.join();
}