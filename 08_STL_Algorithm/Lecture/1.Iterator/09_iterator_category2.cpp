#include <forward_list>
#include <list>
using namespace std;

/* 핵심 정리
    1. 컨테이너의 종류에 따라 반복자에 적용할 수 있는 연산의 종류가 다르다.
        반복자          연산
        list            ++, -- 모두 가능
        forward_list    ++만 가능
    2. 반복자는 적용할 수 있는 연산에 따라 5가지로 분류
        반복자 카테고리             연산
        input iterator             입력(=*i), ++
        output iterator            출력(*i=), ++
        forward iterator           입력, ++, multiple pass
        bidirectional iterator     입력, ++, --, multiple pass
        random access iterator     입력, ++, --, +, -, []
        contiguous iterator        입력, ++, --, +, -, [],
                                   *(i+n) == *(addressof(*a) + n)
*/

int main(){
    // forward_list<int> s1 = {1,2,3};
    list<int> s1 = {1,2,3};

    auto p = begin(s1);

    ++p;
    --p; // single linked list는 backward link가 안되기 때문에 에러가 발생함
}