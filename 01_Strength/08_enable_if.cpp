#include <type_traits>
#include <string>

template<typename T>
class Complex
{
  T real, image;
public:
  Complex(const T& r, const T& i) : real(r), image(i){}

  // std::enable_if_t가 data type conversion이 가능한지 체크함.
  // type conversion이 불가한 경우를 컴파일 타임에 확인하기 위한 API
  template<typename U, typename = std::enable_if_t<std::is_convertible_v<U,T>>>
  Complex(const Complex<U>& c) : real(c.real), image(c.image){}
  
  
  /* 'friend' keyword
   * Why it's needed?
   *   Different specializations of a class template are distinct
   *   types and are not automatically friends. Writing template<typename> 
   *   friend class Complex; inside Complex<T> makes all Complex<U> 
   *   specializations friends, so code like 
   *   Complex<T>::Complex(const Complex<U>& other) can access 
   *   other.re (a private member) or call private helpers of other specializations.
   */

  // Gotchas / alternatives
  // - That friend declaration also serves as a forward declaration of the template.
  // - It grants friendship to all specializations (could be broader than intended).
  //   If you only need a specific non-member function to access privates,
  //   prefer declaring that function as a friend instead.
  // - If you wrote friend class Complex<T>; inside Complex<T>, it would only name the
  //   current specialization (usually unnecessary) — to allow other specializations
  //   you need the template<...> form
  template<typename> friend class Complex;
};

int main()
{
  Complex<float> c1(3.1f,2.3f);
  Complex<double> c2 = c1;  // ok.
  Complex<std::string> c3 = c1; // error. Impossible to convert.
}