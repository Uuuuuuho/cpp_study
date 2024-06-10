#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
using namespace std;

/*  위쪽의 반복자 카테고리일수록 작은 범위 아래로 갈수록 큰 범위의 카테고리임
        반복자 카테고리             연산                                 
        input iterator             입력(=*i), ++                        istream_iterator
        output iterator            출력(*i=), ++                        ostream_iterator
        forward iterator           입력, ++, multiple pass              forward_list
        bidirectional iterator     입력, ++, --, multiple pass          list
        random access iterator     입력, ++, --, +, -, []               deque
        contiguous iterator        입력, ++, --, +, -, [],              array,vector
                                   *(i+n) == *(addressof(*a) + n)        
    1. 왜 iterator category가 중요한가?
        다양한 STL 알고리즘이 작동할 수 있는 컨테이너의 최소 요구 조건을 명시하기 위함
    2. 다양한 알고리즘의 인자로 요구하는 반복자 카테고리가 무엇인지를 알아야한다.
        find: input iterator
        reverse: bidirectional iterator
        sort: random access iterator
    3. list는 sort()를 사용할 수 없다. 하지만 멤버 함수 sort()를 사용할 수 있다.
*/

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    // 첫번째 두번재 인자의 최소 요구 조건? - input iterator
    auto p = find(begin(v), end(v), 5);

    // 최소 요구 조건? - bidirectional iterator
    reverse(begin(v), end(v));

    // quick sort. 최소 요구 조건? - random access iterator
    sort(begin(v), end(v));

    forward_list<int> s = {1,2,3};
    // reverse(begin(s), end(s)); // error

    list<int> s2 = {1,2,3};
    // sort(begin(s2), end(s2)); // 컴파일 에러

    // sort(s2.begin(), s2.end()); // 컴파일 에러
    s2.sort();

    for (auto& n: v)
        cout << n << ", ";
}