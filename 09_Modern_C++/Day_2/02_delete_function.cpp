class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

    void foo(){
        Point p1;
        Point p2(p1);
    }
    /*  To prevent comiler to make copy constructor
        1. Before C++11
        => Only declaration in private.
           Deliberately skip the implementation.
        private:
            Point(const Point& p);
        2. Since C++11
        => "function delete"
        Point(const Point&) delete;
    */
};
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2);   /* Ok. even if copy constructor is in private. */
                    /*  */
}