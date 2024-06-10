#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure
bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	// 주어진 구간에서 "3의 배수"를 찾고 싶다. 
	// std::find_if : 3번째 인자로 단항함수(인자가 한개 인 함수) 전달
	auto p1 = std::find_if(v.begin(), v.end(), foo);

	int k = 0;
	std::cin >> k;

	// 주어진 구간에서 "k의 배수"를 찾고 싶다 ???
	// => 단항함수인 foo에서 main 함수의 지역변수인 k를 사용할수 있어야 합니다.
	// => 일반 함수로는 할수 없습니다. 전역변수등을 사용할수밖에 없습니다.
	auto p1 = std::find_if(v.begin(), v.end(), foo  );

}