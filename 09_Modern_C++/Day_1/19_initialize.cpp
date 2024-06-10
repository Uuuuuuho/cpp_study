#include <vector>
#include <complex>

int main()
{
    /* Problem 1. Many method to initialize variables. */
	int n1 = 10;
	int n2(10); 
	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);

    /* Problem 2. Cannot initialize dynamically allocated array. */
	int* p = new int[3];

    /* Problem 3. Cannot make 10 to 2. */
    std::vector<int> v(10, 2); 
}
class Test
{
    /* Problem 4. Cannot initialize class member array. */
	int x[3];
};



