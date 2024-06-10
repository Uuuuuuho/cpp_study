#include <thread>  
#include <iostream>
#include "chronometry.h"

const int sz = 10000000;

// 해결책 1. 2개 전역변수 사이를 캐쉬 크기만큼 떨어뜨린다.

// long long n1 = 0;
// char padding[64];
// long long n2 = 0;

/*  C++11부터 "alignas" 지시어가 추가되었습니다.
		전역변수의 시작 주소를 "64"의 배수로 해달라는 의미.
*/
alignas(64) long long n1 = 0;
alignas(64) long long n2 = 0;

void f1()
{
	for (int i = 0; i < sz; i++)
	{
		n1 += 1;
	}
}

void f2()
{
	for (int i = 0; i < sz; i++)
	{
		n2 += 1;
	}
}

void test1()
{
	f1();
	f2();
}

void test2()
{
	std::thread t1(f1);
	std::thread t2(f2);

	t1.join();
	t2.join();
}

int main()
{
	chronometry(test1); 
	chronometry(test2); 
}