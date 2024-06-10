#include <iostream>

template<typename T> struct plus
{
  T operator()(const T& lhs, const T& rhs) const
  {
    return lhs + rhs;
  }
};

int main()
{
  plus<int> p;
  int n1 = p(1,2);  // p는 객체지만 함수처럼 사용할 수 있음.
                    // p.operator()(1,2)처럼 해석됨.
  int n2 = p.operator()(1,2); // 이렇게 사용할 수 있음.
  std::cout << n1 << " " << n2 << std::endl;                  
}