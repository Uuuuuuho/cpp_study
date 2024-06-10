#include <vector>
#include <algorithm>
#include <iostream>

int square(int a)       { return a * a; }
int add(int a, int b)   { return a + b; }
void print(int n)       { std::cout << n << std::endl; }
/*  
핵심정리
    STL의 일부 알고리즘은 인자로 함수를 요구.
        단항함수(unary function): 인자가 1개인 함수
        이항함수(binary function): 인자가 2개인 함수

    transform 알고리즘
        단항 함수 버전과 이항 함수 버전을 제공함.
        
*/
int main()
{
    std::vector<int> v1{1,2,3,4,5};
    std::vector<int> v2;
    std::vector<int> v3;

    std::ranges::transform(v1, std::back_inserter(v2), square);

    // v2: 1,4,9,16,25

    std::ranges::transform(v1, v2, std::back_insert(v3), add);

    // v3: 2,6,12,20,30

    std::ranges::for_each(v3, print);
}