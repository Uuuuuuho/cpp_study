#include <iostream>

/* Refer decltype type inference. */
int x = 0;

int  f1() { return x; } /* Return 0, value of 'x'. */
int& f2() { return x; } /* Return nickname not value of 'x'. */

int main()
{
	// f1() = 20;   /* Error. "0 = 20" */
	f2() = 20;      /* Ok. "Nickname of 'x' = 20" */

    /* Key : Function call only comes on the leftside of '=',
             provided that the function returns reference.
    */
}