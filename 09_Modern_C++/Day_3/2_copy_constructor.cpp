class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

    /*  Let's understand copy constructor. */
    /*  Way 1. call by value. 
        => When taking arguments, it's like "Point pt = p2",
           This causes another copy constructor call and results in infinit recursive copy constructor call.
           Thus, it's compilation error.
        => call by value can't be copy constructor argument.
    */
    // Point(Point pt){}

    /*  Way 2. call by non-const lvalue reference. 
        => Not error. Compilable.
        => provided that can take only lvalue, but not rvalue (include temp obj).
            Ex) Point ret = foo(); // error
    */
    Point(Point& pt){}   /* Point& pt = p2 */

    /*  Way 3. call by const lvalue reference.
    */
    Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

Point foo()
{
    Point pt(0, 0);
    return pt;
}

int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2);       /* Copy constructor. */
    Point p4 = foo();   /* Point p4(foo())   */
}




