// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면
	// 1. 비교정책을 전달하지 않는 경우 - 오름 차순
	std::sort( v.begin(), v.end() ); 

	// 2. 비교 정책의 변경
	// A. 일반 함수
	std::sort(v.begin(), v.end(), cmp);

	// B. 함수 객체로 전달
	std::less<int> f; // C++98 부터 이미 표준에 이 클래스 제공.

	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), std::less<int>{} ); // 임시객체
	std::sort(v.begin(), v.end(), std::less{}); // C++17 부터

	// C. 람다 표현식 사용
	std::sort(v.begin(), v.end(), 
			[](int a, int b) { return a < b; } );
}