#include <complex>

int main()
{
    /* C++98 : Different initialization methods. */
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

    /* 
        C++11: Can initialize all vars in the same way.
        This is "uniform initialization".
        Commonly, this is called "brace init"
    */
   int n2 = {10};
   int x2[2] = {1,2};
   std::complex<double> c2 = {1,2};

   int n3{10};
   int x3[2]{1,2};
   std::complex<double> c3{1,2};

   /* Direct initialization : without '=' */
   /* Copy initialization   : with '='    */
}