#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
    auto f1 = [](int a, int b){ return a + b; };
            /* class xxx { operator(); }; xxx(); */
    auto f2 = [](int a, int b){ return a + b; };
            /* class yyy { operator(); }; xxx(); */
    
	// 모든 람다 표현식은 다른 타입입니다.
	// => 타입의 이름은 컴파일러마다 다릅니다.

    std::cout << typeid(f1).name() << " " << (f1) << std::endl;
    std::cout << typeid(f2).name() << " " << (f2) << std::endl;

    auto f3 = [](int a, int b){ return a + b; };
    f3 = [](int a, int b){ return a + b; };         /* Error */
}
