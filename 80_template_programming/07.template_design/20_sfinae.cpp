#include <iostream>

/* 이렇게 작성해도 오류가 발생하지 않음.
 * 만약 mapping하고자 하는 template function이 정의되어있지 않다면?

 * overloading resolution
 *  동일한 이름의 함수가 여러개 있을때 함수를 찾는 순서
 * 아래의 예시로 살펴보자.
 * foo(3.4f)의 함수 찾는 순서
 * foo(short) => exactly matching: 인자의 타입과 정확히 일치되는 함수
 * foo(T)     => template: template을 사용해서 foo(short) 생성
 * foo(double)=> promotion(승격): 데이터 손실이 없는 변환
 * foo(int)   => standard conversion: 데이터 손실 가능성이 잇어도 언어에서 허용하는 변환(표준타입끼리 변환)
 * foo(...)   => variable argument
 */
template <typename T>
void foo ( T )      { std::cout << " T " << std::endl; }
void foo ( int )    { std::cout << " int " << std::endl; }
void foo ( ... )    { std::cout << " ... " << std::endl; }
void foo ( float )  { std::cout << " float " << std::endl; }
void foo ( double ) { std::cout << " double " << std::endl; }

int main() {
    foo(3.4f);
}