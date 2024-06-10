struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

/* Way 1. call by value 
   This makes copy.
*/
void foo(Point pt){}

/* Way 2. call by reference
   This doesn't make copy but make constant property.
   This is useful for read-only.
*/
void foo(const Point& pt){}

/* Is there any way not to make copy and without constant property?
   There is no such way in C++98.
   Since C++11, it's possible.
   Way 3. Provide 2 functions.
*/
void foo(Point &    pt){}
void foo(Point &&   pt){}

/* Way 4. Forwarding reference (T&&).
   2 functions of Way 3 can be made automatically.
*/
template<typename T>
void foo(T&& pt)
{
}


int main()
{
	Point pt(0, 0);

    /* User wanna pass both lvalue and rvalue(temp obj) to foo func. */
	foo(pt);
	foo(Point(0,0));
}
