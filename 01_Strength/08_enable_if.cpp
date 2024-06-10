#include <type_traits>
#include <string>

template<typename T>
class Complex
{
  T real, image;
public:
  Complex(const T& r, const T& i) : real(r), image(i){}
  template<typename U, typename = std::enable_if_t<std::is_convertible_v<U,T>>>
  // std::enable_if_t가 data type conversion이 가능한지 체크함.
  Complex(const Complex<U>& c) : real(c.real), image(c.image){}
  template<typename> friend class Complex;
};

int main()
{
  Complex<float> c1(3.1f,2.3f);
  Complex<double> c2 = c1;  // ok
  Complex<std::string> c3 = c1; // error
}