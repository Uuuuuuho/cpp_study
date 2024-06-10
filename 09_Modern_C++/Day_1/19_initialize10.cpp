#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);	    /* Point(int) constructor */
	Point p2(1, 2);	    /* Point(int, int) constructor */
	Point p3({1, 2});   /* Point(std::initializer_lit<int>) */

	Point p4{1, 2};	    /* 
                            Firstly, lookup std::initializer_list.
                            1. Point(std::initializer_list)
                            2. If there is no.1 constructor, then Point(int, int)
                        */

	// Point p5(1, 2, 3);  /* Error. There is no Point(int, int, int). */
	Point p6{ 1, 2, 3 };    /* Ok. Point(std::initializer_list). */
	Point p7 = { 1,2,3 };   /* Ok. std::initializer_list does not use explicity. */

    /* 
        Conclustion
            When use "std::initializer_list" for constructor argument,
            variadic and same type can be used.
        C++11 wanted this below.
        => It needed this grammar below.
    */
   std::vector<int> v1 = {1,2,3,4,5};
   std::vector<int> v2{1,2,3,4,5};

   /* 
        Since C++11, every STL container can be intialized as arrays. 
        Every container has constructor with "std::initializer_list".
   */
}