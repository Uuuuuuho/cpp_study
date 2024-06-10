#include <iostream>
#include <iterator>
using namespace std;

/* 핵심 정리
    1. 스트림 반복자
        입/출력 스트림에서 요소를 읽거나 쓰기 위한 반복자
        #incldue <iterator>
        4가지 종류의 반복자 제공
        스트림 반복자       출력대상            출력형태
        ostream_iterator    basic_ostream       서식화된 출력
        ostreambuf_iterator basic_ostreambuf    CharT 출력
        istream_iterator    basic_istream       서식화된 출력
        istreambuf_iterator basic_istreambuf    CharT 출력
    2. istream_iterator vs. istreambuf_iterator
        istream_iterator는 white space(space, tab 등)을 입력 받지 못하지만
        istreambuf_iterator를 사용하면 white space 입력 받을 수 있다.
 */

int main()
{
    // ostream_iterator<int> p1(cout);
    istream_iterator<int> p1(cin);
}