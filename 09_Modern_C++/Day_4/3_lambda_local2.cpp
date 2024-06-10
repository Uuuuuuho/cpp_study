#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

   /* 람다의 캡처는 read-only만 권한이 부여됨. */
   /* mutable 람다 표현식 : operator() 연산자를 const 함수로 하지말라는 것. */
   auto f1 = [v1,v2](int a) mutable { v1 = 100; return a + v1 + v2;};

   f1(0); /* 이순간 v1 = 100을 실행하지만, 복사본 v1이 변경됨. */

   std::cout << v1 << std::endl; /* v1 : 10 */

   /* 람다 표현식이 만드는 객체의 크기 
      => 캡처한 변수를 멤버 데이터에 보관.
      => int 2개 멤버 데이터가 있으므로 8.
   */
   std::cout << sizeof(f1) << std::endl; /* ans : 8 */

   class CompilerGeneratedName
   {
      int v1;  /* 지역변수를 캡처하면 컴파일러가 만드는 클래스에 멤버변수가 추가됨. */
      int v2;
   public:
      CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}
      inline auto operator()(int a) { // const{    /* 상수 멤버 함수에서 값을 바꾸는게 안됨. 
                                      //              상수 멤버 함수는 C++에서 기본임.  
                                      //           */
         v1 = 100;
         return a + v1 + v2;
      }
   };

   auto f2 = CompilerGeneratedName(v1, v2);
}





