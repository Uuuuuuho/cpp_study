// 아래 코드가 왜 에러인지 생각해 보세요 ?
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10;  // error. data 는 int 타입이므로
					 // *data 할수 없다.
	}
};
int main()
{
	A a;
}
*/

template<typename T> 
class A
{
	T data;
public:
	void foo()
	{
		*data = 10;  
	}
};
int main()
{
	// 지연된 인스턴스화
	// => 클래스 템플릿의 멤버 함수중에서
	//    사용된것만 실제 인스턴스화("템플릿=>C++클래스")
	//    에 포함된다..
	A<int> a;
	a.foo(); // 사용한 멤버 함수만. 
			 // foo 함수도 템플릿 => C++ 클래스 만들대
			 // 포함됩니다.
}