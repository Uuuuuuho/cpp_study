int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	int x[3] = { 1,2,3 };

    /* Rule 1. There is only symbol name. */
	decltype(p)		d1; 

    /* Rule 2. There is expression with "operator and symbol name"
        => Reference type if the expression is lvalue (=).
        => If not, it's value type.
    */
	decltype(*p)	d2; /* "*p=0" is possible. int& d2. Error coz of non-init. */
	decltype(x[0])	d3; /* "x[0]=0" is possible. int &d3; */

	decltype(n) d; /* "n=0" is possible, there is only symbol name (Rule 1) */
					

    /* Examples... */
    n = 3;
	decltype(n + n) d4; /* "n+n = 10" is not possible, value type. 
                            int d4;
                        */
	decltype(++n)   d5; /* "++n = 10" is not error.
                            lvalue.
                            int& d5
                        */
						
	decltype(n++)   d6; /* "n++ = 10" is error.
                            can not come the leftside of assignment.
                            value type.
                            int d6;
                        */
    
    /* auto and decltype */
    int y[3] = {1,2,3};

    auto a = y[0];  /*  Remove tht reference of rightside and determine.
                        int a = y[0];
                    */
    
    decltype(y[0]) d;   /* int& d */

    // 참조 타입 : int&, double&, char& 등
	// 값 타입   : int, double, char
}

