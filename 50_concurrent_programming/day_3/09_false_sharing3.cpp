#include <thread>  
#include <iostream>
#include "chronometry.h"

const int sz = 10000000;

/*  해결책 3. 전역변수에 직접 연산하지 말고
              지역변수에 연산후에 결과만 전역변수에 담는다.
*/
long long n1 = 0;
long long n2 = 0;

void f1()
{
  long long local = n1;
	for (int i = 0; i < sz; i++)
	{
		local += 1;
		// n1 += 1;
	}
  n1 = local;
}

void f2()
{
  long long local = n2;
	for (int i = 0; i < sz; i++)
	{
		// n2 += 1;
		local += 1;
	}
  n2 = local;
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