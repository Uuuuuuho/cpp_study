#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main(){
    // std::list<int> s = {1,2,3,4,5};
    std::vector<int> s = {1,2,3,4,5};

    std::reverse(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++)
        std::cout << s[i] << std::endl;
    /* STL 컨테이너의 모든 요소를 열거하는 방법
        : [] 연산자 사용 - vector 등 일부 컨테이너만 가능. list 안됨.
        : 반복자 사용 - 대부분 컨테이너에서 사용가능
        : range for 문 사용
        : stream iterator
    
     */

    std::vector<int>::iterator p = s.begin();
    while(p != s.end()){
        std::cout << *p << std::endl;
        ++p;
    }

    for(auto& n : s)
        std::cout << n << std::endl;
}