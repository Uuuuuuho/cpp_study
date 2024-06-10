#include <thread>  
#include <iostream>
#include "chronometry.h"

const int sz = 10000000;

long long n1 = 0;
long long n2 = 0;


void f1()
{
	// 천만번의 루프를 수행하면 1증가
	for (int i = 0; i < sz; i++)
	{
		n1 += 1;
	}
}

void f2()
{
	// f1과 완벽히 동일한데, 결과만 n2에 담습니다.
	for (int i = 0; i < sz; i++)
	{
		n2 += 1;
	}
}

void test1()
{
	// 스레드 한개로 2개 함수 실행
	f1();
	f2();
}

void test2()
{
	// 스레드 2개로 각각의 함수를 실행
	std::thread t1(f1);
	std::thread t2(f2);

	t1.join();
	t2.join();
}

int main()
{
	chronometry(test1); // 스레드 한개로 2개함수 실행
	chronometry(test2); // 스레드 2개로 f1, f2 동시에 실행
}