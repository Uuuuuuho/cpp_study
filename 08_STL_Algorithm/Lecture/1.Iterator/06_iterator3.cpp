#include <iostream>
#include <list>
#include <vector>
using namespace std;
/* 
    1. 반복자 무효화(invalidation)
        vector 등의 컨테이너의 내부 버퍼가 재할당 될때
        반복자가 가리키던 요소가 제거될 때
        컨테이너의 종류에 따라 무효화 되는 조건이 다름
*/
int main(){
    vector<int> v = {1,2,3,4,5};

    auto p = begin(v);

    v.resize(100);

    cout << *p << endl; // 런타임 에러
                        // vector의 주소가 바뀌기 때문
}