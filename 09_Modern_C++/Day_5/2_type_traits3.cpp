// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의 : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// 1. primary template 을 만들고 "using type = T" 넣으세요

template<typename T> struct remove_pointer
{
	using type = T;
};

// 2. 부분특수화를 사용해서 원하는 타입을 얻을수 있도록 
//    타입을 분리 합니다.
//    "int*" => "int" 와 "*" 로 분리
template<typename T> struct remove_pointer<T*>
{
	using type = T;
};

int main()
{
	remove_pointer<int*>::type n2; 

	std::cout << typeid(n2).name() << std::endl; // int
}
template<typename T> void foo(T a)
{
	// 주의!!
	// T에 대해서 remove_pointer 를 사용할때는 반드시 typename 필요합니다.

//	remove_pointer<T>::type n2; // error. typename 필요

	typename remove_pointer<T>::type n2; // 
}