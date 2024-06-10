#include <iostream>

/*  C++11 Postfix return expression
    => return type of functions comes after arguments.
*/
template<typename T1, typename T2>
auto Mul(T1 a, T2 b) -> decltype(a * b)
{
	return a * b;
}

/*  Can do like below as well. 
    This is only available in case of single return statement in the function.
    Type inference of auto.
        Even if return "int&", return "int".
*/
template<typename T1, typename T2>
auto Mul2(T1 a, T2 b)
{
	return a * b;
}

/*  Type inference of decltype. 
    (provided there is only single return statement)
*/
template<typename T1, typename T2>
decltype(auto) Mul3(T1 a, T2 b)
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

