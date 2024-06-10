// C++98 시절의 enum
// enum DAYOFWEEK { sun = 0, mon = 1 };

// C++11 의 새로운 enum
enum class DAYOFWEEK { sun = 0, mon = 1 };

void foo(DAYOFWEEK w)
{
//	int n = w; // error

	int n = static_cast<int>(w); // ok!
}
int main()
{
//	int n1 = sun;			 // error. DAYOFWEEK 이름 반드시 필요
//	int n2 = DAYOFWEEK::sun; // error. int로 변환 안됨

	DAYOFWEEK n3 = DAYOFWEEK::sun; // ok..
							// 핵심 : 보다 엄격하게 사용하라는것
	foo(DAYOFWEEK::sun);
//	foo(100); // error. 안전한코드.. 
}