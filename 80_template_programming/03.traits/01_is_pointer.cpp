#include <iostream>

/* is_pointer 구현 방법
 * 1. is_pointer라는 이름의 구조체 템플릿을 만든다.
 * 2. "enum { value = false }" 멤버로 추가
 * 3. T*인 경우의 partial specialization 버전을 만들고 "enum {value = true }"로 번경
 * 4. const T*, volatile T*, const volatile T*도 필요함.
 */

 /* Meta function (e.g., is_pointer<T>::value)
  * "is_pointer" : 함수이름
  * "T" : 함수 인자
  * "value" : 함수 반환값
  *
  * 컴파일 타입에 사용하는 함수를 가리킴
  * 컴파일 시간에 'true/false"가 결정된다.
  */
template<typename T> struct is_pointer {
    /* 왜 enum을 사용하는가?
     * 구조체 안에 초기화 코드를 작성하고
     * 컴파일 시간에 값을 알 수 있어야 한다.
     * variable을 사용하면 컴파일타임에 값을 알 수 없고, 런타임에야 확인할 수 있다.
     * 최신 문법은 enum보다 "static constexpr type"을 사용한다. 
          */
    enum { value = false };
};

template<typename T> struct is_pointer<T*> {
    enum { value = true };
};

template <typename T>
void fn(const T& arg) {
    if(is_pointer<T>::value) std::cout << "pointer" << std::endl;
    else std::cout << "not pointer" << std::endl;
}

int main() {
    int n = 0;
    fn(n);
    fn(&n);
}

