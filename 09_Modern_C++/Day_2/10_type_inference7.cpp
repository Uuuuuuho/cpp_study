int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	auto a = r; // 

    /*  decltype inference Rule 1. 
            When there is only symbol name in '()'.
            => Determine it as same type with the symbol declaration.
    */

	decltype(n) d1; /* int d1; */
	decltype(r) d2; /* int& d2; but Error since there is no initialization. */ 
	decltype(c) d3; /* const int d3; but Error since there is no initializaiton. */ 
	decltype(p) d4; /* int* d4; */ 

    /* Here is the difference between 'auto' and 'decltype' */
    auto a = r;     /* int a = r */
    decltype(r) d;  /* int& d    */
}