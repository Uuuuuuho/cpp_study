#include <iostream>

struct identity
{
  template <class _Ty>
  [[nodiscard]] constexpr _Ty&& operator()(_Ty&& arg) const noexcept
  {
    return std::forward<_Ty>(arg);
  }
  using is_transparent = int;
};

int main()
{
  identity f;

  int n = 3;

  f(n); // n. 인자로 전달되 ㄴ객체를 아무 변화 없이 그대로 반환

  std::cout << &n << std::endl;
  std::cout << &f(n) << std::endl;
}