#include <iostream>

template <typename T>
// int foo(T) {
typename T::type foo(T) { // int::type
    /* overloading resolution에 따라 "함수 템플릿을 사용하기로
     * 결정"했는데, 템플릿 인자 "T"의 타입을 결정하고
     * "인스턴스화를 할때 실패"했다면?
     * 
     * 1. 컴파일 에러가 발생한다.
     * 2. 에러는 아니고, 함수생성에 실패했으므로 동일 이름의 
     *    다른 함수인 "foo(...)"이 사용된다.
     * 답은 2번!
     * 이러한 현상을 SFINAE (Susbcription Failure Is Not An Error)
     *  치환 실패는 에러가 아니다. 즉, 호출 가능한 "후보군에서 제외"되고,
     *  "동일 이름의 다른 함수가 있으면 사용"된다.
     *  overloading resolution에 따라 호출되는 함수를 결정짓는데
     *  이상적인 함수가 정의되지 않았다고 컴파일이 실패하는 것이 아니라 
     *  대체제가 있다면 대체 함수로 매핑된다!
     */
    std::cout << " T " << std::endl;
    return 0;
}

int foo(...) {
    std::cout << " ... " << std::endl;
    return 0;
}

int main() {
    foo(3);
}

/* 정리
 * 새로운 규칙이 아닌 C++98시절부터 사용되던 규칙
 *  C++20의 concept도 이 개념을 사용하게 됩니다.
 *  requires clauses를 만족하지 못하는 경우는 에러가 아니라
 *  해당 템플릿을 사용하지 않겠다는 것.
 * 
 * SFINAE 개념은 언제 어떻게 활용되는가?
 *  std::enable_if 기술
 *  member detect 기술
 *  그 외 다양한 기법에서 활용
 * 
 * std::enable_if
 *  C++20부터는 대부분 concept 기술로 대체되지만
 *  C++20 이전에는 아주 많이 사용되던 기술이므로 알아둘 필요가 있습니다.
 */