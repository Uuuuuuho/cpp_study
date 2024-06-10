// 9_enum - 32 page


// 인자로 요일을 요구
void foo(int dayofaweek) {}

enum DAYOFWEEK { sun = 0, mon = 1};

int main()
{
	foo(0);  // 0: 일요일, 1 : 월요일...
	foo(sun); // 위 코드 보다 가독성이 좋다.!! 
	
	// 위 코드의 단점 1. 이름 충돌 가능성
	// => 전통적인 enum 은 enum이름 없이 요소 이름만으로도 사용가능
	int sun = 10;
	foo(sun); // enum 상수 ? 지역변수 ? => 지역변수
	foo(DAYOFWEEK::sun); // 

	// 2. 기존 enum 상수는 int로 변환 가능
	int week = DAYOFWEEK::sun; // ok

	foo(DAYOFWEEK::sun); // 
	foo(100);

}