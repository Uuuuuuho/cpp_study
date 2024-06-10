// 2_typename
struct Test
{
	enum { data = 0 };
	using DWORD = int;
};
int p1 = 0;

template<typename T> void foo(T a)
{
	// 아래 코드에서 * 의 의미를 생각해 보세요
	Test::data  * p1;	// 이 문맥에서 * 는 곱하기의 의미
	Test::DWORD * p1; 	// 이 문맥에서 * 는 포인터 변수를 선언하기위한
						// 연산자
	// "클래스이름::이름" 에서 "이름" 은
	// 1. 값		: enum 상수, static member data
	// 2. 타입	: using 또는 typedef 등.. 

	// 의존이름(dependant name)
	// => 템플릿 인자에 의존해서 꺼내게 되는 이름
	// => "T::이름"
	// => 컴파일러는 기본적으로 값으로 해석한다.

	T::data  * p2; // error. p2를 찾을수 없다.
	T::data  * 10; // ok

//	T::DWORD * p2; // error. 컴파일러는 DWORD를 값으로 해석해서
					//       * 를 곱하기로 생각, 
	typename T::DWORD* p2; // ok
					// dependant name 을 값이 아닌 
					// 타입으로 해석해 달라는 의미.
}


int main()
{
	Test t;
	foo(t);
}