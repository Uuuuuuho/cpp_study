#include <iostream>

template<typename T>
class Complex
{
  T real, image;
public:
  Complex(const T& r, const T& i) : real(r), image(i){}

  // generic constructor: 서로 다른 타입의 인스턴스에 대한 복사생성자
  // 인자로 넘어오는 인스턴스의 템플릿을 별도로 작성주면 끝!
  // This templated constructor allows implicit conversion between
  // Complex<U> and Complex<T> when the underlying types are convertible.
  // e.g., Complex<double> cd = Complex<float>{...};
  // Note: because this is a template constructor, it is considered
  // in overload resolution and can suppress the implicit copy/move
  // constructors unless care is taken (C++11's rule: templated
  // constructors do not suppress the implicitly-declared copy ctor
  // in this simple case, but be aware of overload ambiguity in more
  // complex classes).
  template<typename U>
  Complex(const Complex<U>& c): real(c.real), image(c.image){}

  // Give other instantiations access to private members so the
  // templated constructor can read c.real / c.image.
  template<typename> friend class Complex;
};

int main(){
  Complex<float> c1(3.1f, 2.3f);
  Complex<float> c2 = c1;  // copy constructor
  Complex<double> c3 = c1; // generic constructor
}