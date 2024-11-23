#include <iostream>

template<typename T1, typename T2>
// return type을 compile time에 inference하도록 하고자 하는 경우
// decltype(a + b) add(const T1& a, const T2& b) { 
/* 하지만 a가 declare 되지 않았다는 컴파일 에러.. 
 * 왜??
 * decltype(a+b): "a+b" 표현식의 결과로 나오는 값의 "타입"
 * 모든 변수는 "선언 후에 사용"되어야 한다.
 */
// auto add(const T1& a, const T2&b) ->decltype(a + b) {// C++11부터 후위 타입추론이 가능하도록 기능이 지원됨.
auto add(const T1& a, const T2& b){ // C++14부터
    return a + b;
}