#include <iostream>
#include <algorithm> 

// 비교 정책을 인자로 전달 받는 sort
void Sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
//			if (x[i] > x[j])				
			if ( cmp(x[i], x[j]) == true )
				std::swap(x[i], x[j]);
		}
	}
}
//------------------------
/* The functions below are same since they have same return type and argument type. */
bool cmp1(int a, int b) { return a > b; }
bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, &cmp1); 
}
