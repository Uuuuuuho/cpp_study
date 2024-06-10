class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};

/* 
    Integer literal suffix needs "unsigned long long" 
    User defined literal must be follow this rule, that users attach "_"
*/
// Meter operator""m(unsigned long long n)
Meter operator""_m(unsigned long long n)
{
	Meter me(static_cast<int>(n));
	return me;
}
int main()
{
	/* Every literal has a type. */
	double d = 3.4;	// 3.4 is double
	float f = 3.4f; // "f" means compile this as float

	// Since C++11, user defined literal is possible
	
    /*
	Meter n1 = 3m;  
                        compiler looks up the predefined function.
				        operator""m(3)
    */
	Meter n1 = 3_m; /* User defined lister use case. 
                        -3_m : operator""m(3).opeartor-()
                    */

//	Gram  n2 = 3gram;
}
