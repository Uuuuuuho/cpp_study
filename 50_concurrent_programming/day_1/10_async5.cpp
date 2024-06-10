#include <chrono>
#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <string>
#include <numeric>
#include <execution>

static const int NUM = 100000000; // 1억

std::vector<int> v1, v2;

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

    long long ret = f1();

    std::cout << ret << std::endl;
}