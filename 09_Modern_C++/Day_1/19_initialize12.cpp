#include <vector>
#include <complex>
// aggregate initialization

struct Point
{
	int x, y;

	Point()             : x(0), y(0) {}	// 1
	Point(int a, int b) : x(a), y(b) {}	// 2
};

int main()
{
    /* 
        Problem 1. Different initialization methods.
        => Use baces.
    */
   int n1{10};
   int n2{10};
   int x[2]{1,2};
   std::complex<double> c{1,2};

    /* 
        Problem 2. Cannto initialize dynamically allocated arrays.
        => Able to use "{}" init.
    */
   int* p = new int[3]{1,2,3};

    /* 
        Problem 3. Cannot make a vector with value 1~10.
        => Able to use "{}".
    */
    std::vector<int> v(10, 2);  /* make 10 elements as 2. */
    std::vector<int> v2{1,2,3,4,5,6,7,8,9,10};

	Point p1;	
	Point p2(1, 2);
}

class Test
{
    /* 
        Problem 4. Cannot initialize class with array.
        => Able to use {} init.
    */
   int x[3]{1,2,3};
};