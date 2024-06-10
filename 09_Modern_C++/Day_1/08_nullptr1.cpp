#include <iostream>

void foo(int* p) {}
template<typename T>
void forward_foo(T arg)
{
	foo(arg);   /* Argument is int type. Thus, this is error. */
}


int main()
{
	int n = 0;
	foo(0); /* Ok */
	// foo(n); /* Error. Only translate literal 0 into 0.
    //             Initialized pointer is not translated into pointer. 
    //         */
    
    // foo(0); /* Ok */
    // forward_foo(0); /* ?? Request to pass '0'. 
    //                     Error. 
    //                 */

    forward_foo(nullptr); /* Ok */
}