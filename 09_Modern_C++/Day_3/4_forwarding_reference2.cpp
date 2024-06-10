// 91 page
int main()
{
	int n = 10;

    /* double pointer */
	int *p = &n;
	int* *pp = &p;  /* Ok. */

    /* Can't make double reference. rvalue reference is different from double reference. */
	int& r = n;     /* Ok. */
	int& &rr = r;   /* Error by handcoding. */


	using LREF = int&; 
	using RREF = int&&;

    /* It's not error that reference of reference when compilation.
       => Follow reference collapsing rule.
    */

	/* "Reference collapsing". Always lvalue reference except for "&& &&". */
	LREF& r3 = ? ;  /* int& &   => int&  , lvalue reference */
	RREF& r4 = ? ;  /* int&& &  => int&  , lvalue reference */
	LREF&& r5 = ? ; /* int& &&  => int&  , lvalue reference */
	RREF&& r6 = ?;  /* int&& && => int&& , rvalue reference */
}

template<typename T> void foo(T a)
{
	T& r = a;   /* Think about type of 'r'. 
                   int& & r = a;
                   => int& r = a;
                */
}





