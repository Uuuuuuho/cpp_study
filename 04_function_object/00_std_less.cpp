#include <iostream>
// #include <memory>
#include <utility>

template <typename T = void> struct less
{
  [[__DEPRECATED]] typedef T _FIRST_ARGUMENT_TYPE_NAME;
  [[__DEPRECATED]] typedef T _SECOND_ARGUMENT_TYPE_NAME;
  [[__DEPRECATED]] typedef bool _RESULT_TYPE_NAME;

  [[nodiscard]] constexpr bool operator()(const T& lhs,
                                          const T& rhs) const
  {
    return lhs < rhs;
  }
};

template<>
struct less<void>
{
  template <class T1, class T2>
  [[nodiscard]] constexpr auto operator()(T1 lhs, T2 rhs) const
    noexcept(noexcept(std::forward<T1>(lhs) < std::forward<T2>(rhs)))
    -> decltype(std::forward<T1>(lhs) < std::forward<T2>(rhs))
    {
      return std::forward<T1>(lhs) < std::forward<T2>(rhs);
    }
    using is_tranparent = int;
};