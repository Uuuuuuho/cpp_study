#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
using namespace std;

/* 핵심 정리
    1. ostream_iterator 생성
        ostream_iterator(ostream_type& stream, const CharT* delim)
        ostream_iterator(ostream_type& stream)
    2. ostream_iterator 연산
        연산        연산의 결과
        ++          no-op
        *           no-op
        =           write to stream
 */

int main()
{
    // ostream_iterator<int> p(cout, ", ");

    // ostream_iterator<int> p(cout);
    ofstream f("a.txt");
    ostream_iterator<int> p(f, ", ");

    *p = 20;
    ++p;        // no operation
    *p = 30;
}