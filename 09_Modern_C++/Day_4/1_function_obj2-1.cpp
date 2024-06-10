#include <iostream>
#include <vector>
#include <algorithm>

/* 1. 일반 함수 foo는 main의 지역변수 k를 사용할 수 없지만 */
bool foo(int n) { return n % 3 == 0; }

/* 2. 함수객체는 main의 지역변수 k를 사용(캡처)할 수 있다. */
struct IsMod
{
	int value;

	IsMod(int n) : value(n){}
	bool operator()(int n) const{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;
	IsMod f(k); // f는 단항함수 처럼 사용가능한데. k값을 보관하고 있습니다.
	bool b = f(6);// 6 % k 를 조사

	// f : operator() 함수 기능 + main 지역변수 k값

	auto p1 = std::find_if(v.begin(), v.end(), f) ;
									// "단항함수 f + k값"
								    // 을 같이 전달하는 의미
	auto p2 = std::find_if(v.begin(), v.end(), IsMod{k});
}
// 클로져(Closure)
// => 자신이 포함된 문맥의 지역변수를 캡쳐할수 있는 일급객체(함수)

// C++에서 일반 함수는 클로져가 될수 없지만
//        함수객체는 클로져가 될수 있다.

// C++98 : std::max() => 함수 입니다.
// C++20 : std::ranges::max() => 함수객체 입니다.

// 일급 객체란 ?(first class object)
// 1. 함수 인자로 사용할수 있고
// 2. 함수 반환값으로 사용가능하고
// 3. 복사, 대입등이 가능한 객체(
int n1; // n1 은 일급객체 입니다.

void foo() {} // C/C++에서 함수(함주 주소)도 함수 인자로 사용가능합니다.
			  // 그래서 함수도 일급객체라고 합니다