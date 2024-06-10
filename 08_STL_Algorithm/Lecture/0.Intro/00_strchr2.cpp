#include <iostream>
#include <cstring>

template<typename T>
T* efind(T* first, T* last, T val){
    while (first != last && *first != val)
        ++first;

    return first == last ? 0 : first;
}

int main()
{
    double x[10] = {1,2,3,4,5,6,7,8,9,10};
    double *p = efind(x, x+10, 5.0);

    if (p == 0)
        std::cout << "fail" << std::endl;
    else
        std::cout << "success : " << *p << std::endl;
}