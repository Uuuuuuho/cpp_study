#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/* 알고리즘
    멤버 함수가 아닌 일반 함수로 되어있습니다.
        STL 알고리즘은 특정한 컨테이너가 아닌 다양한 컨테이너에 대해서 사용할 수 있는 일반 함수로 되어있습니다.
    STL 알고리즘을 사용하기 위한 헤더 파일
        <algorithm>
        <numeric>
        <memory>
    알고리즘은 컨테이너를 알지 못한다.
*/

int main()
{
    vector<int> v = {1,2,3,1,2,3,1,2,3,1};
    // list<int> v = {1,2,3,1,2,3,1,2,3,1};

    // auto p = find(begin(v), end(v), 3);
    auto p = remove(begin(v), end(v), 3);
    /* 1,2,1,2,1,2,1,2,3,1이 남게됨
        뒤에 3개의 "2,3,1"은 남아있음
        컨테이너의 크기를 줄이지 않음
        이는 인자의 컨테이너로부터 전달되는 반복자의 타입을 알 수 없기 때문
        따라서 컨테이너의 크기를 줄이려면 컨테이너의 erase 멤버함수를 사용해야합니다
    */

    for(auto&it: v)
        cout << it << " ";

    cout << endl;
    v.erase(p, end(v));
    for(auto&it: v)
        cout << it << " ";

    return 0;
}