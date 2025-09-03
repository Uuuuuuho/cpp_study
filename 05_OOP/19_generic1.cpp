#include <iostream>
#include <typeinfo>

template<int N>
struct Int
{
  // 템플릿 non-type 파라미터 N을 정수 상수로 보관하는 단순한 래퍼 타입
  // 예: Int<3>::num == 3
  static const int num = N;
};

template <typename T, typename U>
struct add
{
  // 두 타입의 정적 멤버 num을 더한 결과를 다시 Int<...> 형태로 묶어
  // result라는 이름으로 제공한다. 이 연산은 컴파일 타임에 수행된다.
  // 즉 add<Int<1>, Int<2>>::result는 Int<3> 타입이다.
  typedef Int<T::num + U::num> result;
};

int main()
{
  typedef Int<1> one;
  typedef Int<2> two;

  // one, two는 각각 Int<1>, Int<2> 타입을 의미
  // add<one, two>::result는 컴파일 타임에 계산되어 Int<3> 이 된다.
  typedef add<one, two>::result three; // three == Int<3>

  // three::num은 3을 출력한다. 모든 계산은 컴파일 타임에 이루어짐.
  std::cout << "Addition result : " << three::num << std::endl;
}