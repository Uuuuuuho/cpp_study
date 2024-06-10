#include <iostream>
#include <set>

class Point
{
    int x{0},y{0};
public:
    Point() = default;
    Point(int x, int y):x(x),y(y){}
    bool operator<(const Point& pt) // const를 붙여야합니다.
    { return x< pt.x;}
};

int main()
{
    std::set<Point> s;
    s.emplace(1,2);
}