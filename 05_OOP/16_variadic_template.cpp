#include <iostream>

template <typename T>
void print(T arg)
{
  std::cout << arg << std::endl;
}

/* 
  "..."는 function parameter pack이라고 부름. 
  variadic template function은 std template function 뒤에 와야함.
  그렇지 않은 경우, compile error가 발생함.
*/
template <typename T, typename... Types>
void print(T arg, Types... args)
{
  std::cout << arg << ", ";
  print(args...);
}

int main()
{
  print(1, 3.1, "abc");
  print(1,2,3,4,5,6,7);  
}