#include <map>
#include <string>
using namespace std::literals;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

void f1(int n) {}
void f2(Point pt) {}

int main()
{
	f1(3);      /* 
                    Finally, meaning of "int n = 3".
                    Copy constructor when passing arguments.
                */
    f1({3});    /* Available since C++11. "int n = {3}". */
	f2({1,2});  /* Point pt = {1,2} */
    /* ============================= */
	std::map<std::string, std::string> m;

	std::pair<std::string, std::string> p("mon", "Monday");
	m.insert(p);

	m.insert({ "tue", "Tuesday" }); // ok.. 
    /* this results in "..insert(const std::pair&)" */
}

Point f3() 
{ 
	// return Point(1, 2); /* C++98 */
    // return Point{1, 2};
    return {1, 2}; /* Ok.. Compiler knows this function returns Point object. */
}
