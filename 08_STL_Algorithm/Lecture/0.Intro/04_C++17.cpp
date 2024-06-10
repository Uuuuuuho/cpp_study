#include <iostream>
#include <list>
using namespace std;

template<typename T> class List
{
public:
    List(int sz, T initVal) {}
};

int main(){
    List<int> s1(10, 0);
    List      s2(10, 0); // C++17부터 가능

    list<int> s3 = {1,2,3};
    list      s4 = {1,2,3}; // C++17부터 가능
}