#include <iostream>
#include <string>
#include <vector>

template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;

    /* 'move' is way fater than 'swap'. */
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

/*  What to learn in 'move'? 
    1. 'move' is way faster than memory copy swap.
    2. What should user do to replace 'std::string' with user defined type?
    People p1("kim");
    People p2 = std::move(p1); // What should user do with this?
*/