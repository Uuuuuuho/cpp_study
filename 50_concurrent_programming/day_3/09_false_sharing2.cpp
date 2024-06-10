#include <thread>  
#include <iostream>
#include "chronometry.h"

const int sz = 10000000;

// �ذ�å 1. 2�� �������� ���̸� ĳ�� ũ�⸸ŭ ����߸���.

// long long n1 = 0;
// char padding[64];
// long long n2 = 0;

/*  C++11���� "alignas" ���þ �߰��Ǿ����ϴ�.
		���������� ���� �ּҸ� "64"�� ����� �ش޶�� �ǹ�.
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