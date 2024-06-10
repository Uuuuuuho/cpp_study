/*  In C++, constexpr can be used for 3 types. 
    1. constexpr value
    2. constexpr function
    3. constexpr constrol - C++17
    constexpr function : If compiler knows the argument value,
                         return value can be determined in compile time.
*/

// int Factorial(int n)
constexpr int Factorial(int n)
/* Compiler can only use 'constexpr' when a function is simple computation. */
{
	return n == 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int n = 5;

	int arr1[Factorial(5)]; 

	int arr2[Factorial(n)]; /*  Error. 
                                Cannot figure out in compile time. 
                                g++ 
                            */
						
	int s1 = Factorial(n); 

	int s2 = Factorial(5);  /*  Comiler must konw arguemnt in compile time.
                                but it differs on the condition of compilers.
                            */
    
    const int s3 = Factorial(5);     /* runtime or comile time depending on compiler. */

    constexpr int s4 = Factorial(5); /* Must perform in compile time. */
}