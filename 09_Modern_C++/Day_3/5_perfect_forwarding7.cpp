#include <iostream>
#include "stopwatch.h" // 이헤더 추가하세요
						// git 에 소스 있습니다. 복사해 놓으세요

int& f3(int a, double d, int& r) 
{
	std::cout << a << ", " << d << std::endl;

	return r; 
}

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	StopWatch sw(true); // 생성자에서 시간기록,
						// 소멸자에서 걸린시간 출력
	return f(std::forward<T>(arg)...);
}
int main()
{
	int n = 10;

	int& ret = chronometry(f3, 3, 2.1, n);
}