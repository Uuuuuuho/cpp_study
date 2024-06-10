template<typename T> void foo(T a) {}

int main()
{
    /* Type inference by passing argument. */
	foo(10);
	
    /* Consider T a = 10; */
    auto a = 10;    /* Simply, auto is same as template. */

    /*  It's hard to figure out which type of 'auto' is. 
        However, there are several ways to figure out with 'template'.
    */
	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

    /*  auto inference is same as template inference. 
        Think about types below.
        T a1 = n;   Rule 1.
                    => Remove const, volatile, reference property of the right-side expression.
                    => auto type inference.
    */
	auto a1 = n;  // a1 : int
	auto a2 = r;  // a2 : int
	auto a3 = c;  // a3 : int
	auto a4 = cr; // a4 : int

    /* T& a5 = n;   Rule 2.
                    => Remove righthand side reference property.
    */
	auto& a5 = n;   // auto :  int   a5 : int&
	auto& a6 = r;   // auto :  int   a6 : int&
	auto& a7 = c;   // auto :  const int   a7 : const int&
	auto& a8 = cr;  // auto :  const int   a8 : const int&

    /* Rule 3. auto&& : Tomorrow! Important topic. */
}
/* 
auto 는 pretty 같이 출력 포맷 알려주는 매크로는 없는거죠?
=> C++ 표준에는 없습니다.
=> boost 라이브러리의 type_name 이라는 클래스로 출력가능합니다.

auto의 type inference는 modern C++에서 적용되기 시작했나요 ?
template 규칙 : C++98 문법
auto : auto 자체의 키워드가 C++11(modernC++)에서 도입
*/