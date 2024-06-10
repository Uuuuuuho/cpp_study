#include <iostream>
#include <cstring>

/* 이전 단계의 문제점
    - 구간의 타입과 찾는 요소의 타입이 연관되어 있다.
        (double 배열에서는 double만 검색 가능, int 검색 안됨)
    - 구간의 표현은 반드시 포인터만 사용해야한다.
* 해결책
    - 구간의 타입과 검색할 요소의 타입을 다른 타입을 사용한다.
    - 구간의 시작, 마지막을 전달 받을 때는 포인터(*)를 표기하지 않는다.
 */
template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 val){
    while (first != last && *first != val)
        ++first;

    return first == last ? 0 : first;
}

int main()
{
    double x[10] = {1,2,3,4,5,6,7,8,9,10};
    double *p = efind(x, x+10, 5.0);

    if (p == 0)
        std::cout << "fail" << std::endl;
    else
        std::cout << "success : " << *p << std::endl;
}