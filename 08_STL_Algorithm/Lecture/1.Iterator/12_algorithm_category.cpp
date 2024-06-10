#include <iostream>
#include <iterator>

template<typename InputIt, typename T>
InputIt
efind(InputIt first, InputIt last, T val){
    while(first != last && *first != val)
        ++first;
    return first;
}

int main(){
    int x[3] = {1,2,3};

    int* p = efind(x,x+3,2);
    std::cout << *p << std::endl;
}