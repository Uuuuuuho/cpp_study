#include <iostream>

void f0() {}
void f1(int a) {}
int& f3(int a, double d, int& r) { return r; }

// 코딩 관례
// 1. 인자가 한개가 아닌 여러개도 완벽한 전달되어야 합니다.
// => 가변인자 템플릿으로 만드는 것이 관례

// 2. 리턴값도 완벽히 돌려주는 것이 좋습니다.
// => decltype(auto) 기술로 반환

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	return f(std::forward<T>(arg)... );
}
int main()
{
	int n = 10;
	
	chronometry(f0);
	chronometry(f1, 3);
	int& ret = chronometry(f3, 3, 2.1, n);
	ret = 100;

	std::cout << n << std::endl; // 100
}