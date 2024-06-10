#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

void f1(Point  pt) {}   /* call by value : create copy. */
void f2(Point& pt) {}   /* call by reference : not create copy */

Point pt(1, 2);

Point foo()     /* return by value : return temp obj. */
{
	return pt;
}

Point& goo()    /* return by reference : do not create temp obj */
{
    return pt; // return nickname of pt
}

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);

    foo().x = 10;   /* Error. temp_obj.x = 10 */
    goo().x = 10;   /* Ok.. pt.x = 10 */
}

/* Provided that never return local var. */
Point& hoo()
{
    Point pt(1, 2); /* Local var */
    return pt;  /*  Bug. never use.
                    local var, member, etc.
                    Gotta guarantee not to destruct after function call.
                */
}







