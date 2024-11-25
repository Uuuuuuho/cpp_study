#include <iostream>

struct static_member
{
	static_member()  { std::cout << "static_member()"  << std::endl;}
	~static_member() { std::cout << "~static_member()" << std::endl;}
};
struct instance_member
{
	instance_member()  { std::cout << "instance_member()" << std::endl;}
	~instance_member() { std::cout << "~instance_member()" << std::endl;}
};

template <typename T>
struct Object
{
	instance_member m1;
	static static_member m2; // static_member를 사용한적이 없어서 생성하지 않음.
	/* 멤버함수 뿐만 아니라 static 멤버 변수도 접근하지 않으면 생성되지 않음.
	 * static 멤버함수나 멤버 변수에서 초기화를 적용하는 경우 버그의 원인이 될 수 있음.
	 */
};

template <typename T> static_member Object<T>::m2;

int main()
{
	std::cout << "--------" << std::endl;
	Object<int> obj;
	obj.m2; // static_member에 접근하면 인스턴스를 생성함.
	std::cout << "--------" << std::endl;
}