#include <chrono>
#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <string>
#include <numeric>
#include <execution>
#include "chronometry.h"

static const int NUM = 100000000; // 1억

std::vector<int> v1, v2;

long long f2()
{
    const int v1_size = v1.size();
    const int v2_size = v2.size();

    /* v1, v2 vector innner product를 "4개의 스레드로 합 구하기" 
        async의 장접 : 기존의 "return으로 반환하는 함수"를 직접 사용가능

        1일차 예제 : std::thread로 스레드 생성, 결과를 꺼내기 위해
                    std::ref()등이 변수 전달해야 했다..!
    
    */

    std::future<long long> ft1 = std::async([v1_size, v2_size] {
        return std::inner_product(&v1[0], &v1[v1_size / 4], &v2[0], 0LL); });

    std::future<long long> ft2 = std::async([v1_size, v2_size]
        { return std::inner_product(&v1[v1_size / 4], &v1[v1_size / 2], &v2[v2_size / 4], 0LL); });

    std::future<long long> ft3 = std::async([v1_size, v2_size]
        { return std::inner_product(&v1[v1_size / 2], &v1[v1_size * 3 / 4], &v2[v2_size / 2], 0LL); });

    std::future<long long> ft4 = std::async([v1_size, v2_size]
        { return std::inner_product(&v1[v1_size * 3 / 4], &v1[v1_size - 1], &v2[v2_size * 3 / 4], 0LL); });

    return ft1.get() + ft2.get() + ft3.get() + ft4.get();
}

void fill_vector()
{
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> dist(0, 100);

    v1.reserve(NUM);
    v2.reserve(NUM);

    for (int i = 0; i < NUM; ++i)
    {
        v1.push_back(dist(engine));
        v2.push_back(dist(engine));
    }
}


// vector 내적 구하기
long long f1()
{
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0LL);
}

int main()
{
    fill_vector();

    // long long ret = f1();
    // long long ret = f2();
    // std::cout << ret << std::endl;

    // f1(), f2()의 수행시간을 비교.
    // chronometry : 인자로 전달된 하수를 실행하고 수행시간 출력
    //               "chronometry.h"에 있음.
    long long ret1 = chronometry(f1);
    std::cout << ret1 << std::endl;
    long long ret2 = chronometry(f2);
    std::cout << ret2 << std::endl;

}

/*  정리
    1. std::thread, std::jthread
    2. std::promise/std::future 모델
    3. std::packaged_task 모델
    4. std::async()

    ft.get()을 하지 않을대 현상들
*/