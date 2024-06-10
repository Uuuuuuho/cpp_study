// 아래 템플릿은 "인자가 한개인 함수를 생성" 할수 있습니다.
template<typename T> void f1(T arg) {}

// 가변 인자 함수 템플릿
// => "인자의 갯수, 타입에 제한 없이 모든 형태의 함수 생성가능"
template<typename ... Types> void f2(Types ... args) {}

int main()
{
	f2();
	f2(1);
	f2(1, 3.4);
	f2(1, 3.4, 'A');	// Types : int, double, char
						// args  : 1, 3.4, 'A'


	f1(10);	 // f1(int) 생성
	f1(3.4); // f1(double) 생성
//	f1(10, 3.4); // error
}