#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(){
    // list<int> s = {1,2,3,4,5};
    // list<int>::iterator p = s.begin();
    // vector<int> s = {1,2,3,4,5}; // list를 vector로 변경했다고 가정해보자
    int s[5] = {1,2,3,4,5}; // vector를 array로 변경했다고 가정해보자

    // auto p1 = s.begin(); // array는 컴파일 에러를 발생시킴
    auto p1 = begin(s); // array도 iterator 컴파일 에러를 발생시키지 않음
                        // "begin()"은 STL container와 array도 사용가능

    int n = size(s); // s.size();
    cout << n << endl;

    auto p2 = end(s); // "end()"는 맨 끝 아이템의 다음을 가리키기 때문에 dereference 금지
    *p2 = 10; // 런타임 에러
}