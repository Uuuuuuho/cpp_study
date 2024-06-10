#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

// 4항 함수
void foo(int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a,b,c,d);
}

int main()
{
    foo(1,2,3,4); // 4항 함수..

    // 4항 함수 => 2항으로
    bind(&foo, 10, _2, _1, 20)(1,2); // 10, 2, 1, 20
}