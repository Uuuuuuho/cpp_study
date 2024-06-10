#include <iostream>

/*  1.  It's difficult to inference type of return value. 
        decltype is very useful in this case.
    2. Error below.
*/
template<typename T1, typename T2>
decltype(a * b) Mul(T1 a, T2 b)   /* Error. a & b is used before declaration. */
{
	return a * b;
}

int main()
{
	std::cout << Mul(3, 4.1)   << std::endl;

    // a = 20;     /* Error. No decalaration. */
    // int a = 0;
    // a = 10;     /* Ok. var must be decalred before its usage. */
}

