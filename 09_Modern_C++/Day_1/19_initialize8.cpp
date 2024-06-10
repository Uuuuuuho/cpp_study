class Point
{
	int x, y;
public:
    Point() {}
	Point(int a, int b) : x(a), y(b) {}
};
class Rect
{
	Point pt; /* Error. Whent there is no default constructor. */
public:
    /* 
        User code   Compiler code
        Rect() {}   Rect() : pt() {}
    */
	Rect() {}
};

class Rect2
{
    /* Since C++11, initialize like below. */
    Point pt1{0, 0};
    // Point pt2(0, 0); /* Error */
};

int main()
{
	Rect r1;
    Rect2 r2;
}

