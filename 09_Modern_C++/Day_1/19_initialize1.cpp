#include <iostream>

int x = 10;

/* "field initialization" grammar */
class Test
{
    /* Principle of "field initialization" */
	int value1 = 0;     /* Look here init value */
	int value2 = ++x;   /* Change constructor below */
public:	
    /* Compiler changed code */
	Test() {}   /* Test() : value1(0), value2(++x){} */
	Test(int n) : value2(n) {}  /* Test(int n) : value1(0), value2(n){} 
                                    In "Test(int n)", there is no "++x" since 'value2' is assigned as 'n'. */
};

int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; 
}