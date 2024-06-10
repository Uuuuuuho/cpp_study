#include <iostream>
#include <list>
using namespace std;

/* Multipass guarantee
    2개의 반복자가 다음을 만족
        i1 == i2라면, *i1 == *i2
        i1 == i2라면, ++i1 == ++i2
    2개 이상의 반복자가 컨테이너의 요소에 동일하게 접근함을 보장
    list의 반복자는 multipass를 보장한다
    stream iterator와 insert iterator는 multipass를 지원하지 못한다.
*/
int main(){
    list<int> s1 = {1,2,3};

    auto i1 = begin(s1);
    auto i2 = i1;

    if(i1==i2)
        cout << (*i1 == *i2) << endl;
        cout << (++i1 == ++i2) << endl;
}