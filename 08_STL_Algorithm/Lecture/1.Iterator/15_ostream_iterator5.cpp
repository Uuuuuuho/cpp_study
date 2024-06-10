#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> p1(cout, ", ");
    /* 내부적으로 cout을 이용하여 출력하기 때문에 template type에 다양한 type이 올 수 있음. */
    *p1 = 10; // cout << 10 << ", " 
    // ostreambuf_iterator<char> p2(cout);

    // 문자만 출력하는 경우 ostreambuf_iterator가 더 빠름
    ostreambuf_iterator<char> p2(cout.rdbuf());
    /* ostreambuf는 char 인자만 올 수 있음. */
    *p2 = 'A'; // streambuf->sputc("A")

    ostreambuf_iterator<wchar_t> p3(wcout.rdbuf());

    *p3 = L'A';
}