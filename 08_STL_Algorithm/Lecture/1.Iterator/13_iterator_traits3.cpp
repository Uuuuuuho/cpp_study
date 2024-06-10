#include <iostream>
#include <list>
#include <iterator>
using namespace std;

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

/* 핵심정리
    member type             definition
    value_type              T
    difference_type         singed integer type
    reference               value_type&
    pointer                 value_type*
    iterator_category       컨테이너마다 다른 정의

    ** STD structure **
    struct iterator_traits<_Tp*>
    {
      using iterator_concept  = contiguous_iterator_tag;
      using iterator_category = random_access_iterator_tag;
      using value_type	      = remove_cv_t<_Tp>;
      using difference_type   = ptrdiff_t;
      using pointer	      = _Tp*;
      using reference	      = _Tp&;
    };
*/

/* tag dispatching 기술 정리 - "C++ Template Programming" */
template<typename T> 
void eadvance_imp(T& p, int n, random_access_iterator_tag){
    p = p + n;
}
template<typename T> 
void eadvance_imp(T& p, int n, input_iterator_tag){
    while(n--) ++p;
}
template<typename T> 
void eadvance(T& p, int n){
    eadvance_imp(p, n, typename iterator_traits<T>::iterator_category());
    // eadvance_imp(p, n, typename T::iterator_category());
}


/* 핵심 정리
    1. value_type 대신에 auto/decltype을 사용할 경우
        - type deduction 규칙을 정확히 알고 사용해야한다. - "C++ 중급 과정" 참고
*/
template<typename T>
typename iterator_traits<T>::value_type
sum(T first, T last)
{
    // typename iteratr_tratis<T>::value_type s = 0;

    // decltype(*first) s = 0; // error. decltype(*포인터타입)
    typename remove_reference_t<decltype(*first)>::type s= 0;

    while(first != last){
        s = s + *first;
        ++first;
    }
}

int main(){
    // list<int> s = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int s[10] = {1,2,3,4,5,6,7,8,9,10};

    auto p = begin(s);

    eadvance(p, 5);
    cout << *p << endl;
}