#include <iostream>
#include <typeinfo>

template<int N>
struct Int
{
  static const int num = N;
};

template <typename T, typename U>
struct add
{
  typedef Int<T::num + U::num> result;
};

int main()
{
  typedef Int<1> one;
  typedef Int<2> two;

  // compiler가 "three"를 3으로 치환함.
  typedef add<one, two>::result three;

  std::cout << "Addition result : " << three::num << std::endl;
}