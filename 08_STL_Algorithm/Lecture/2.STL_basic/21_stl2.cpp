#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> v = {1,2,3,1,2,3,1,2,3,1};

    // auto p = remove(begin(v), end(v), 3);
    v.remove(3); // STL "remove"보다 좋음. 찾으면 바로 노드를 제거하기 때문

    for(auto&it: v) cout << it << " ";
    cout << endl;
    
    
    // v.erase(p, end(v)); // list에서 성능 낭비
    // for(auto&it: v) cout << it << " ";


    return 0;

}