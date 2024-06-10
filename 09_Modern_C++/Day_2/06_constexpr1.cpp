#include <iostream>

template<typename T, std::size_t SZ>
struct array
{
};

int main()
{
	int n = 10;
	const int c1 = 10; 
	const int c2 = n;  

    /* Pick errors. */
	int arr1[10];   /*  Ok. */
	int arr2[n ];   /*  C89 : Error.
                        Array size should be know in compile time.
                        C99 : Ok.
                        Many comiler does not support this.
                        g++ able.
                        vc  not able.
                    */
	int arr3[c1];   /* Ok. When comilation, c1 is '10'. */
	int arr4[c2];   /* Error. */

    /*  Type of constant
        1. Compiler can figure out the value.
        2. Compiler may figure out the value.
            "not changeable" : runtime constant.
            Other languages call this as 'readonly' or 'immutable',
            not 'constant'.
    */

    /*  In C++, there are things that must know in compile time.
        => size of array template argument, etc.
    */
	array<int, 10> a1;
	array<int, n>  a2;
	array<int, c1> a3;
	array<int, c2> a4;
}
