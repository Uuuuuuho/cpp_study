#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #2

class People
{
private:
	std::string name;
	std::string address;
public:
	/*
	// 인자가 2개 이상인 setter
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	void set(std::string&& n, std::string&& a)
	{
		name = std::move(n);
		address = std::move(a);
	}
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}
	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}
	*/
	// 결론 : 인자가 N개인 setter 를 완벽한 전달 하는 것을 직접 만들면
	//       N^2 개의 setter를 만들어야 합니다.
	// => 너무 많습니다. T&& 로 하세요.

	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name, addr);
	//	p.set(std::move(name), addr);
	//	p.set(name,			   std::move(addr));
	//	p.set(std::move(name), std::move(addr));
}

/* 질문 메일 : smkang@codenuri.co.kr */