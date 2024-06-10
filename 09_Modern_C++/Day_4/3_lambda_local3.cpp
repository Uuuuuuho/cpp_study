#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// [ v1,  v2] : capture by value
	// [&v1, &v2] : capture by reference

	auto f1 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; };

	f1(0);  // v1 = 100 에서 v1은 main 의 지역변수를 변경

	std::cout << v1 << std::endl; // 100


	//--------------------------------------------------------
	class CompilerGeneratedName
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline auto operator()(int a) const
		{
			v1 = 100;				
			return a + v1 + v2;
		}
	};
	auto f1 = CompilerGeneratedName(v1, v2); // main 의지역변수
}