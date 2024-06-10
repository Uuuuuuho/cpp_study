#include <iostream>
#include <list>
using namespace std;

/* 핵심 정리
    1. back_inserter() 함수
        - 후방 삽입 반복자(back_inserter_iterator)를 생성해주는 도움함수
        - 대부분 back_inserter_iterator를 직접 사용하기 보다는 back_inserter()를 사용함
        - "클래스 템플릿은 반드시 템플릿 인자를 지정해야하지만 함수 템플릿은 템플릿 인자를 생략할 수 있다." - C++17이전까지
*/

template<typename T>
back_insert_iterator<T> // return type
back_inserter_test(T& c)
{
    return back_insert_iterator<T>(c);
}

int main()
{
    int x[5] = {10,20,30,40,50};
    list<int> s = {1,2,3,4,5};

    // back_insert_iterator<list<int>> p(s);
    // copy(x, x+5, p);

    // 위의 2줄보다 아래 한줄이 readable & easy to use
    copy(x, x+5, back_inserter_test(s));
    copy(x, x+5, back_inserter(s)); // STD back inserter

    for(auto& n: s)
        cout << n << endl;
}