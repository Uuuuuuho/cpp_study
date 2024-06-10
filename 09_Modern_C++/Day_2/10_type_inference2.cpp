#include <iostream>

/*  Type reference
	1. argument value type : void foo(T)
		=> remove property of "const, volatile, reference" and then determine type.
	2. argument reference type : void foo(T&)
	3. argument T&& type : void foo(T&&)
*/
/*  Rule 2. Provided that function argument is reference (T&),
			=> Remove type of reference for function argument.
			=> Remain 'const' and 'volatile'.
*/
template<typename T> void foo(T a)
{
	a = 100;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
int main()
{
	foo<int>(3);

	foo(10);	// T=int
	foo(3.4);	// T=double

	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
				/* In VC++ 							*/
	foo(n); 	/* T = int,			a = int& 		*/
	foo(c); 	/* T = const int,	a = const int& 	*/
	foo(r); 	/* T = int,			a = int& 		*/
	foo(cr);	/* T = const int,	a = const int& 	*/
}