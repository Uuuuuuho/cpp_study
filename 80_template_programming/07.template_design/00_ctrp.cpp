#include <iostream>

/* CTRP (Curiously Recurring Template Pattern)
 *  "기반 클래스에서 파생 클래스의 클래스 이름"을 사용할 수 있게 하는 기술
 * CTRP 핵심
 * 1. "기반 클래스를 템플릿"으로 만들고
 * 2. 파생 클래스를 만들때 "자신의 클래스 이름을 기반 클래스의 템플릿 인자"로 전달
 * 
 * CRTP를 사용한 event 처리
 *  "가상 함수가 아닌 함수를 가상함수 처럼 동작"하도록 디자인
 */

template <typename T>
class Base
{
private:
    /* data */
public:
    void fn() {
        // 여기서 파생클래스(Derived) 이름을 사용할 수 없을까?
        // 파생클래스의 순서가 나중이기 때문에 알 수 없지만.
        // 즉, 어떤 파생클래스가 기반클래스를 호출할지 알 수 없지만.
        // 이를 가능하게 해주는게 "CTRP"라는 기술임.
        T obj; // Derived obj 

        std::cout << typeid(T).name() << std::endl;
    }
};

class Derived : public Base <Derived> {
private:
    /* data */
public:
};

int main() {
    Derived d;
    d.fn();
}