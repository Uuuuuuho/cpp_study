struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};


int main()
{
	Point pt(0, 0);

	// Rule 1. (non-const) lvalue reference can point only lvalue.
	Point& r1 = pt;
	Point& r2 = Point(0, 0);

	// Rule 2. (const) lvalue reference can point both lvalue and rvalue.
	const Point& r3 = pt;
	const Point& r4 = Point(0, 0);

	// Rule 3. rvalue reference can point rvalue (rvalue reference)
    /*  => point temporary object without constant property.
        => move, for perfect forwarding.. C++11
    */
	Point&& r5 = pt;
	Point&& r6 = Point(0, 0);

    /*  Why not learn const Point&&?
        => Barely used.
        => Explain afeter 'move'
    */
}

void draw_line(const Point& from, const Point& to)
{
	// pt 가 가리키는 객체를 읽기만
}

void init_point(Point& pt)
{
	// pt 가 가리키는 객체를 변경
	pt.x = 10;
	pt.y = 10;
}