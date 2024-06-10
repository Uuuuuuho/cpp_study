#include <cassert>

/* 
    C assert : runtime validation check
    static_assert : compile time validation check

    1. Available both inside and outsize of function
    2. Expression must be expectable in the compile time
    3. Only compilation overhead. strongly recomendded!
        => C++ keyword
    4. This is only for safety, not for runtime validation.
*/

static_assert(sizeof(int*) == 8, "error not 64 bit");


void foo(int age)
{
	// It is recommended to check validation 
    // before function argument
	assert(age > 0);

	int* p = new int[age];

	delete[] p;
}
int main()
{
	foo(10);
//	foo(-10); // Case of passing negative argument by a mistake.
}