#include <iostream>
#include <algorithm>

/* STL 문자 검색 알고리즘 */
int main()
{
    double x[] = {1,2,3,4,5,6,7,8,9,10};
    double *p = std::find(x, x+10, 5);

    if (p == 0)
        std::cout << "fail" << std::endl;
    else
        std::cout << "success : " << *p << std::endl;
}