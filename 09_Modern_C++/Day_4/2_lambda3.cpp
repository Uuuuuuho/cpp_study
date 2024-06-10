#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
    /* 핵심 1. 람다 표현식을 auto 변수에 담아서 일반함수처럼 사용가능함. */
    auto f = [](int a, int b){ return a + b; };
            /* class xxx { operator(); }; xxx(); */
    
    int n1 = f(1, 2);   /* 1 + 2 */
    int n2 = f.operator()(1,2); /*  Ok. 
                                    결국 f는 함수 객체이므로 이렇게 사용하는것도 가능함.
                                */
    
    //--------------------------------
	// 다음중 에러를 모두 골라 보세요

	auto f1 = [](int a, int b) { return a + b; }; // ok
	
	auto& f2 = [](int a, int b) { return a + b; }; // error

	const auto& f3 = [](int a, int b) { return a + b; }; // ok
	
	auto&& f4 = [](int a, int b) { return a + b; }; // ok

	// 위 4줄 에서 "제일 좋은 것은 f1" 입니다.. f1 으로 사용하세요.
}
