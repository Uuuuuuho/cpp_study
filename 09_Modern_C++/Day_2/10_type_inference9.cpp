#include <iostream>

int x = 0;

int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4);
    /*  int ret = foo(1, 3.4); // auto removes right-side reference property and determine the type. */

    ret = 200;  /* x is not modified */

    /* decltype(function call) : return type investigation */
    decltype(foo(1, 3.4)) ret2 = foo(1, 3.4);   /* decltype(function call) is used only to investigate return type. */
    /* int& ret2 = foo(1, 3.4) */

    /*  decltype(auto) 
        => put rightside onto 'auto'.
        => type inference by rightside.
        => C++14
    */
    decltype(auto) ret3 = foo(1, 3.4);  /* decltype Rule */
                /* int& ret3 = foo(1, 3.4) */
    auto ret5 = foo(1, 3.4);    /* auto rule (remove right reference) */
                /* int ret5 = foo(1, 3.4) */
}