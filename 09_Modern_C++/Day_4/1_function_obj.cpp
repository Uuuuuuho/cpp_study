// 1_함수객체0.cpp

int Add(int a, int b) { return a + b; }

void foo( int(*f)(int, int) ) 
{
}

int main()
{
	foo(&Add);
	foo(Add);  // 함수 이름의 함수 주소로 암시적 변환 가능(decay)

	// 람다 표현식
	// => 함수이름(주소)가 필요한 자리에 함수 구현을 보낼수 있는 문법
	// => 익명의 함수를 만드는 문법
	// => [] : 람다 표현식이 시작됨을 알리는 기호
	// => C++11 도입, 다른 언어 에서는 "클로져"라고도 부름
	foo( [](int a, int b) { return a + b; } );
}