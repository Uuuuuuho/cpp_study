#include <iostream>
#include <list>
using namespace std;
#include <iterator>
/* 
    1. 반복자의 2가지 형태
        1-1. user define type으로 만들어진 반복자 - value_type이 있다.
        1-2. raw pointer
            raw pointer 안에는 "member type"이 없기 때문에 알고리즘 함수를 만들때 문제가 생기게된다.
    2. iterator_traits
        - <iterator>
        - Raw pointer에는 "member type"이 없다는 문제를 해결하기 위한 도구
        - 반복자의 value_type이 필요할 때, iterator_traits를 통해서 value_type을 사용한다.
    3. value_type을 사용하는 2가지 방식
        3-1. T::value_type                  : T가 Raw pointer라면 error
        3-2. iterator_tratis<T>::value_type : T가 Raw pointer라도 문제 없음.
*/

// template<typename T> struct iterator_traits
// {
//     using value_type = typename T::value_type;
// };
// // 핵심: 포인터 버전을 부분 특수화
// template<typename T> struct iterator_traits<T*> // 컴파일 에러가 발생하지만, 이 부분은 STL에서 제공하고 있음.
// {
//     using value_type = T;
// };

template<typename T>
typename iterator_traits<T>::value_type sum_traits(T first, T last)
{
    // T: int*
    // typename T::value_type s = 0;

    typename iterator_traits<T>::value_type s = 0;

    while (first != last){
        s = s + *first;
        ++first;
    }
    // C++11부터
    // auto s = *first;
    return s;
}

template<typename T>
typename T::value_type sum(T first, T last)
{
    typename T::value_type s = 0;

    while (first != last){
        s = s + *first;
        ++first;
    }
    // C++11부터
    // auto s = *first;
    return s;
}

int main()
{
    list<int> s = {1,2,3,4,5,6,7,8,9,10};
    // vector<int> s = {1,2,3,4,5,6,7,8,9,10};

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    // int n = sum(begin(s), end(s));
    // int n = sum(begin(arr), end(arr)); // compile error
    int n = sum_traits(begin(arr), end(arr));
    cout << n << endl;
}