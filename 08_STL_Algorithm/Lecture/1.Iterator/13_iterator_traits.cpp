#include <iostream>
#include <list>
using namespace std;

template<typename T>
typename T::value_type sum(T first, T last)
{
    // 구간의 합을 보관할 변수
    // T: 반복자 타입
    // ? s = 0;
    // T::value_type: 반복자가 가리키는 타입
    typename T::value_type s = 0;

    while (first != last){
        s = s + *first;
        ++first;
    }
    // C++11부터
    // auto s = *first;
    return s;
}

int main()
{
    list<int> s = {1,2,3,4,5,6,7,8,9,10};
    // vector<int> s = {1,2,3,4,5,6,7,8,9,10};

    int n = sum(begin(s), end(s));

    cout << n << endl;
}