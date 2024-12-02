#include <iostream>
/* type transformation을 직접 구현해보자
 * remove_pointer 구현 방법
 * 1. remove_pointer라는 이름의 구조체 템플릿을 만들고
 * 2. "using type = T" 멤버로 추가
 * 3. 원하는 타입(포인터를 제거한 타입)을 얻을 수 있도록 부분 특수화 버전을 제공.
 */

template <typename T> struct remove_pointer {
    using type = T; // typedef T type;
};

/* Partial specialization을 통한 포인터 제거의 근원
 * 아래 템플릿에서 "T"는 "int"가 됨
 */
template <typename T> struct remove_pointer<T*> {
    using type = T; // typedef T type;
};


template <typename T>
void fn(const T& arg) {

    // remove_pointer<int*>::type n1;
    
    // int가 아닌 템플릿 타입으로 적용하려면 ::type을 사용하면 되는데
    // type이 타입일 수 있지만 값일 수 있어서 이를 확실히 하기위해
    // "typename"을 앞에 작성해야함.
    typename remove_pointer<T>::type n1;

    std::cout << typeid(n1).name() << std::endl; // int
}

int main() {

    int n = 10;
    fn(&n);
    fn(n);
}