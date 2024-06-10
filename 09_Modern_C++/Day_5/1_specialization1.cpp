#include <iostream>

// 최초의 specialization 문법을 만든 의도는
// => 아래 vector 처럼..
// => 특정 타입에 대한 최적화된 틀(템플릿)을 제공하자는 의도 였습니다.

// => 그런데, modern c++ 이후에 이문법으로 다양한 기술을 만들어서 사용합니다.

// STL vector 의 구현원리를 생각해 봅시다.
template<typename T>
class vector
{
	T* buff;
public:
	vector(std::size_t sz)
	{
		buff = new T[sz];
	}
};

// vector<bool> 의 경우는 구현 방법을 변경합니다.
// => bool에 맞도록 최적화된 구현을 사용하자는 의미!
template<>
class vector<bool>
{
	int* buff;
public:
	vector(std::size_t sz)
	{
		buff = new int[(sz/32) + 1];
					// 0  ~ 31 : int 한개(4byte)
					// 32 ~ 63 : int 2개
					// vector<bool> v(100) 은 int 4개로 관리.
					// 100 바이트가 아닌 16바이트로 관리
	}
};


int main()
{
	vector<int>  v1(100);
	vector<bool> v2(100); // 이 순간을 생각해 봅시다.
}