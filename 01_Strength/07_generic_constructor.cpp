#include <iostream>

template<typename T>
class Complex
{
  T real, image;
public:
  Complex(const T& r, const T& i) : real(r), image(i){}

  // generic constructor: 서로 다른 타입의 인스턴스에 대한 복사생성자
  // 인자로 넘어오는 인스턴스의 템플릿을 별도로 작성주면 끝!
  template<typename U> Complex(const Complex<U>& c): real(c.real), image(c.image){}
  template<typename> friend class Complex;
};

int main(){
  Complex<float> c1(3.1f, 2.3f);
  Complex<float> c2 = c1;  // copy constructor
  Complex<double> c3 = c1; // generic constructor
}