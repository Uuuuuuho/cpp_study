#include <vector>
#include <algorithm>
#include <iostream>

/* 
    projection ≠ “find”
*/

struct Point {
    int x, y;
};

int main()
{
    namespace rgs = std::ranges;

    std::vector<Point> v{{1,1}, {2,2}, {3,3}, {4,4}};

    auto ret1 = rgs::find_if(v, [](const Point& pt){ return pt.y == 3; });

    // Same function
    auto ret2 = rgs::find(v, 3, &Point::y);

    std::cout << ret1->x << " " << ret1->y << std::endl;    
    std::cout << ret2->x << " " << ret2->y << std::endl;    
}