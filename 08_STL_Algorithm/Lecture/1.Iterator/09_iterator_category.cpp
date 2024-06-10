#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/* 반복자 카테고리
    1. vector는 sort() 알고리즘을 사용할 수 있다.
    2. list는 sort() 알고리즘을 사용할 수 없다.
    3. 왜 사용할 수 없을까?
*/

int main(){
    // vector<int> v = {1,3,5,7,9,2,4,6,8,10};
    list<int> v = {1,3,5,7,9,2,4,6,8,10};

    sort(begin(v), end(v));

    for(auto& n: v)
        cout << n << ", ";
}