#include <iostream>
#include <cstring>

/* STL 문자 검색 알고리즘 */
int main()
{
    char s[] = "abcdefg";
    char *p = strchr(s, 'c');

    if (p == 0)
        std::cout << "fail" << std::endl;
    else
        std::cout << "success : " << *p << std::endl;
}