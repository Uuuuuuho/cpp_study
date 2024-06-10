#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

/* STL 알고리즘은 "함수"를 "인자"로 가지는 경우가 많이 있습니다.
    알고리즘의 활용도를 더욱 높여줍니다.
    for_each, transform

    단항함수: 인자가 한개인 함수
    이항함수: 인자가 두개인 함수
    
    일반 함수뿐만 아니라, 함수객체, 람다표현식을 사용할 수 있다.
        ()로 호출 가능한 모든 객체를 사용 가능합니다.

*/

void foo(int& a)
{
    // cout << a << endl;
    a = a*2;
}

struct Show
{
    string sep;
    ostream& os;

    // Functor는 생성자에서 상태를 갖도록 설계할 수 있습니다.
    Show(ostream& o = cout, string s = "\n"): os(o), sep(s){}

    void operator()(int a)
    {
        os << a << sep;
    }
};

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    // for_each(begin(v), end(v), foo);

    Show s(cout, "\t");
    /* for_each는 함수 인자를 하나만 받을 수 있음.
       functor를 사용해야만 아래와 같은 기능을 구현할 수 있음
    */
    for_each(begin(v), end(v), s);

    for(auto&it: v) cout << it << " ";
    cout << endl;

    return 0;
}