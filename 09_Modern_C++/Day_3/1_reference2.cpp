#include <iostream>

// 90 page
/* no.1 */void foo(int& a)       { std::cout << "int&" << std::endl; }        /* when taking lvalue. */
/* no.2 */void foo(const int& a) { std::cout << "const int&" << std::endl; }  /* when taking both lvalue and rvalue. */
/* no.3 */void foo(int&& a)      { std::cout << "int&&" << std::endl; }       /* when taking rvalue. */

int main()
{
	int n = 10;
	foo(n);     /* Call no.1, otherwise call no.2 */
	foo(10);    /* Call no.3, otherwise call no.2 */
}

