#include <print>

/* 
    ADL은 함수끼리 검색하기 때문에 충돌이 발생하는 반면,
    함수객체에서는 충돌이 발생하지 않기 때문에 
    C++20부터 함수 객체를 사용하여 구현되어있음.
*/

namespace mystd
{
	class string {};

	template<typename T> 
	void max(const T& a, const T& b) { std::println("std::max"); }

	namespace ranges
	{
//		template<typename T> 
//		void max(const T& a, const T& b) { std::println("std::ranges::max"); }

		struct max_fn
		{
			template<typename T> 
			void operator()(const T& a, const T& b) { std::println("std::ranges::max"); }
		};

		max_fn max;
	}
}

int main()
{
	mystd::string s1, s2;

	mystd::max(s1, s2);
	mystd::ranges::max(s1, s2);

	// using namespace mystd::ranges;
	max(s1, s2);
}