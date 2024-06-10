#include <iostream>
#include <iterator>
#include <list>
using namespace std;

/* 핵심 정리
    1. 스트림 반복자(stream iterator)
        입/출력 스트림에서 요소를 읽거나 쓰기 위한 반복자
        #include <iterator>
        4가지 종류의 반복자 제공

        스트림 반복자           출력 대상           출력 형태
        ostream_iterator        basic_ostream       서식화된 출력
        ostreambuf_iterator     basic_ostreambuf    CharT 출력
        istream_iterator        basic_istream       서식화된 입력
        istreambuf_iterator     basic_istreambuf    CharT 입력
    2. ostream_iterator
        출력 스트림(ostream, ofstream, ostringstream)을 사용해서 출력을 하는 반복자
        copy 등의 알고리즘 함수를 사용해서 스트림에 출력할 때 사용
 */

int main()
{
    int n = 10;

    cout << n << endl;

    ostream_iterator<int> p(cout, ", ");

    *p = 20; // cout << 20 << ", "
    *p = 30; // cout << 30 << ", "

    list<int> s = {1,2,3};

    copy(begin(s), end(s), p);
    fill_n(p, 3, 0); // 0, 0, 0
}