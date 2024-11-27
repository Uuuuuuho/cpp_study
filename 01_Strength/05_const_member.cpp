#include <iostream>
#include <set>

class Point
{
    int x{0},y{0};
public:
    Point() = default;
    Point(int x, int y):x(x),y(y){}
    /* 인자로 오는 pt는 변하지 않음을 의미합니다.
     * bool operator overloading으로 Point 클래스간 비교가 필요한 경우 사용됩니다.
     */
    bool operator<(const Point& pt) // const를 붙여야합니다.
    { return x< pt.x;}
};

int main()
{
    std::set<Point> s;
    s.emplace(1,2);
}