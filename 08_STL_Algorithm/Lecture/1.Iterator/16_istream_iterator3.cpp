#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

/* 핵심정리
    1. istream_iterator
        default constructor는 end of stream이 됩니다
*/

int main()
{
    ifstream f("16_istream_iterator3.cpp");
    // istream_iterator<char> p1(cin);
    // istream_iterator<char> p1(f); // 파일을 입력으로도 받을 수 있음
    // istream_iterator<char> p1(f), p2; // p2는 end of strema을 가짐
    istreambuf_iterator<char> p1(f), p2; // istreambuf는 white space를 구분하여 입력받기 때문에 출력도 구분하여 출력 가능합니다
    ostream_iterator<char> p3(cout);

    // *p3 = *p1;
    copy(p1, p2, p3);
}