class Test
{
	int data = 0;
public:
	void foo()
	{
		// 멤버 데이타 캡쳐 ?
		//auto f = [](int a) { return a + data; }; // error

		// auto f = [data](int a) { return a + data; }; // error
							// data 는 지역변수 아닙니다.

		// 핵심 : 람다표현식에서 멤버데이타를 사용하려면 this를
		//		 캡쳐하면 됩니다.
		auto f = [ this ](int a) { return a + data; };



	}
};

int main()
{
	Test t;
	t.foo(); 
}