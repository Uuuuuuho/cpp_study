#include <iostream>
#include <iterator>
using namespace std;

/*  핵심 정리
    ostream (basic_ostream<>)
        입력으로 들어오는 문자를 parsing & character로 변환
    rdbuf()
        stream 객체가 사용하는 streambuf의 포인터를 반환하는 stream의 멤버함수
    basic_streambuf<>::sputc()
        streambuf에 한 문자를 출력하는 함수
    ostream_iterator
        stream(cout)을 사용해서 화면 출력 - 서식화된 출력
    ostreambuf_iterator
        streambuf를 사용해서 화면 출력 - 문자 타입만 출력
        성능면에서 ostream_iterator보다 빠름
*/

int main()
{
    cout << 65;
    streambuf* buf = cout.rdbuf();
    buf->sputc(65); // A를 화면 출력..
}