#include <iostream>

template<typename T>
class Complex
{
  T real, image;
public:
  Complex(const T& r, const T& i) : real(r), image(i){}

  // generic constructor
  template<typename U> Complex(const Complex<U>& c): real(c.real), image(c.image){}
  template<typename> friend class Complex;
};

int main(){
  Complex<float> c1(3.1f, 2.3f);
  Complex<float> c2 = c1;  // copy constructor
  Complex<double> c3 = c1; // generic constructor
}