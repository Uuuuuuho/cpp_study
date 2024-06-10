#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    char a = 0, b = 0, c = 0;

    // cin >> a;
    // cin >> b;
    // cin >> c;

    a = cin.rdbuf()->sgetc();
    // b = cin.rdbuf()->sgetc(); // 그대로 사용하면 버퍼의 이동이 없이 입력을 그대로 받음
    // c = cin.rdbuf()->sgetc(); // 다만 white space를 구분하지 못함
    b = cin.rdbuf()->snextc();
    c = cin.rdbuf()->snextc();

    cout << a << "," << b << "," << c << endl;

}