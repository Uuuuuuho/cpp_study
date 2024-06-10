// forwarding reference 이야기

template<typename T> class Test
{
public:
	// 아래 함수의 인자가 "forwarding reference" 일까요 ?
	// => 아닙니다.!!
	// => 아래 코드에서 T는 함수 템플릿이 아닌 클래스 템플릿의 인자
	// => 아래 함수는 함수 템플릿이 아닙니다. 클래스 템플릿의 일반 멤버함수
	void foo(T&& arg)
	{
	}

	// forwarding reference 가 되려면 함수 자체가 템플릿 이어야 합니다.
	template<typename U>
	void goo(U&& arg)
	{
	}
};
int main()
{
	int n = 0;
	Test<int> t; // 이 순간 T는 int 로 결정되었습니다.
				 // 따라서, foo 의 모양은 "foo(int&&)"로 확정됨.
	// 아래 코드를 생각해보세요. 에러가 있을까요 ?
	t.foo(n);   // error
	t.foo(10);  // ok

	t.goo(n); // ok
	t.goo(10);// ok

	// auto&& 는 rvalue reference 일까요 ? 
	// forwarding reference 일까요 ?  => 정답
	// T&& r1 = 10
	auto&& r1 = 10; // ok  int&& r1 = 10
					// auto : int,  auto&& : int&&
	auto&& r2 = n;  // ok  int&  r2 = n
					// auto : int&, auto&& : int& && => int&

//	decltype(n)&& 	// decltype은 ()안의 변수의 선언부를 보고 타입을 결정함. 따라서 int&&으로 결졍됨.
}
