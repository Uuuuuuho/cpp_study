#include <algorithm>

// 1. 일반 함수는 자신만의 타입이 없습니다.
//    signature(리턴타입과 파라미터) 가 
//    동일한 모든 함수는 같은 타입입니다.

// 2. 모든 함수 객체를 다른 타입이다.
//    signature 가 동일해도, 다른 타입이 된다.

struct Less
{
	inline bool operator()(int a, int b) const { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) const { return a > b; }
};
//----------------------

// 비교 정책을 교체 할수 있는데, 정책 함수가 치환되어서 
// 성능저하가 없는 sort()
// "함수객체 + 템플릿"의 조합으로 만드는 기술
template<typename T> 
void Sort(int* x, int sz, T cmp)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]) == true) 
				std::swap(x[i], x[j]);
		}
	}
}
int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2); Sort(x, 10, f1);
	Greater f2; f2(1, 2); Sort(x, 10, f2);

	/*
	if (사용자 입력 == 1)
	{
		Less f1;
		Sort(x, 10, f1);
	}
	else
	{
		Greater f2;
		Sort(x, 10, f2);
	}
	*/
}