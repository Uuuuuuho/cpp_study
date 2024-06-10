int main()
{
	int x[3] = { 1,2,3 };

	int n = x[0];
    /*  auto : determine left expression by right expression.

    */

    decltype(n) d;  /* int d */

    const int c = 0;

    auto a1 = c;    /* int a1 = c; */

    decltype(c) d1; /* cosnt int d1. Error coz this is not initialized. */

    /*  type inference : compiler determines type */
    /*  type inference 3 cases
        1. template
        2. auto
        3. decltype
        => 1, 2 have the same rule.
        => 3 has different rule.
    */
}