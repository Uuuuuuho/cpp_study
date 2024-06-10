#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;

public:
	// C++98 시절의 코드
	// C++98 시절 : 100점
	// C++11 이후 : best 는 아닙니다. move 지원안되는 setter
//	void set(const std::string& n) { name = n; } // 항상복사
//	void set(const std::string& n) { name = std::move(n); }
									// n은상수 객체이므로 항상복사

	// setter 만들때 move 지원 하려면 2개 만들어야 합니다.
	// C++11 이후에 최선의 코드입니다.
	// 해결책 1. 2개 만드세요
//	void set(const std::string& n) { name = n; }
//	void set(std::string&& n) { name = std::move(n); }

	// 해결책 2. T&& 사용하면 위 2개를 자동생성합니다.
	template<typename T>
	void set(T&& n)
	{
		// 다음중 맞는 것은 ?
		name = n;					// 1. 항상 복사
		name = std::move(n);		// 2. 항상 move
		name = std::forward<T>(n);	// 3. 사용자가 set의인자를
						// lvalue로 보내면 복사
						// rvalue로 보내면 move
	}

};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set(s1);
	p.set(std::move(s2));

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

}
