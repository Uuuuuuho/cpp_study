#include <iostream>
#include <iterator>
using namespace std;

// CharT는 character가 아닌 다른 타입이 들어오는 경우를 대비하기 위해서
// default template은 type을 사용자가 입력하기 잊는 경우를 위해서
template<typename T, typename CharT = char, typename Traits = char_traits<CharT>>
class eostream_iterator
{
    // ostream*    stream;
    basic_ostream<CharT, Traits<char>>* stream;
    const CharT* delimiter;
public:
    eostream_iterator(ostream& os, const CharT* const deli = 0): stream(&os), delimiter(deli) {}

    eostream_iterator& operator*(){ return *this; }
    eostream_iterator& operator++(){ return *this; }
    eostream_iterator& operator++(int){ return *this; }

    eostream_iterator& operator=(const T& v){
        *stream << v;
        if(delimiter != 0)
            *stream << delimiter;
        return *this;
    }
};

int main()
{
    eostream_iterator<int> p(cout, ", ");

    *p = 10; // (p.operator*()).operator=(10)
}