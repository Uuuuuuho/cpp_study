#include <iostream>
#include <vector>

struct Point3D
{
	int x, y, z;
};

/* 
	Use 'begin' & 'end' fo user defined object.
	However, this only works when the members are contiguous in memory.
	Normally, there is not guarantee for user defined object.
	It could be useful for user defined array.
*/
int* begin(Point3D &p){return &(p.x);}
int* end(Point3D &p){return &(p.z)+1;}

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  /* Does this work? Then, what should I do? */
		std::cout << n << std::endl; 

}

