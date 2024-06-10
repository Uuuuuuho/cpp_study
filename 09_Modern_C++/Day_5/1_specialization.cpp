// 3_부분특수화1 - 156 p
#include <iostream>

// C++98 문법
// primary template
template<typename T> class Stack
{
public:
	void push(T a) { std::cout << "T" << std::endl; }
};

// partial specialization(부분 특수화(전문화))
/* 알고리즘이 바뀌는 경우, 템플릿을 별도로 분리하기 위함. */
template<typename T> class Stack<T*>
{
public:
	void push(T* a) { std::cout << "T*" << std::endl; }
};

// specialization(특수화(전문화))
template<> class Stack<char*>
{
public:
	void push(char* a) { std::cout << "char*" << std::endl; }
};

int main()
{
	Stack<int>   s1; s1.push(0);
	Stack<int*>  s2; s2.push(0);
	Stack<char*> s3; s3.push(0);
}