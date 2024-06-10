#include <iostream>

/* 
  compile time에 type이 정의됨.
  정의된 type으로 연산을 할 수 있음.
  이렇게 타입을 가지고 컴파일 타임에 생성된느 코드로 프로그래밍 하는 것을
  메타 프로그래밍이라고 함.
*/
template <int N>
struct Factorial
{
  static const int result = N * Factorial<N-1>::result;
};
template<>  // recursive call의 leaf node
struct Factorial<1>
{
  static const int result = 1;
};

int main()
{
  std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;
}