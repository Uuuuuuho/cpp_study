// 4_rvalue - 87 page
int x = 0;
int  foo() { return x;}
int& goo() { return x; }

int main()
{
    /*  lvalue : can come on left-side.
                 has name, and can be used over single equipment.
                 & operator can figure out address.
                 Ex) function that returns refenrence.

        rvalue : can not come on the left-side.
                 no name, available on single equipment only.
                 can not figure out address by & operator.
                 Ex) literal(10, 3.4, etc.), temporary object.
    */
	int v1 = 10, v2 = 10;

	v1 = 20;        /* v1 : lvalue, 10 : rvalue */
	10 = v1;        /* lvalue can come on both sides, but rvalue can only come on the right-side. */
	v2 = v1;
	int* p1 = &v1;
	int* p2 = &10;  /* Error. */

    foo() = 10;     /* Error. */ 
    goo() = 10;     /* Ok. */

    const int c = 0;
    c = 20;     /*  Is 'c' lvalue? rvalue? 
                    Answer : immutable lvaue.
                */
}