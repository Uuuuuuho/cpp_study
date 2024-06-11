#include <vector>
#include <algorithm>
#include <iostream>

/* 
핵심정리

unary predicator vs projection

projection	pointer to member data
            pointer to member function
            단항 함수(함수 객체)

find_if	    단항 조건자(unary predicator).
            한 개의 인자를 받아서 bool(또는 bool로 변환 가능한 타입)을 반환.
*/

struct Point {
    int x, y;
    int get_y() const{ return y; }
};

int main()
{
    namespace rgs = std::ranges;

    std::vector<Point> v{{1,1}, {2,2}, {3,3}, {4,4}};

    auto ret1 = rgs::find(v, 3, &Point::y);
    auto ret2 = rgs::find(v, 3, &Point::get_y);
    auto ret3 = rgs::find(v, 3, [](const Point& p){ return p.x; });

    std::cout << ret1->x << " " << ret1->y << std::endl;    
    std::cout << ret2->x << " " << ret2->y << std::endl;    
}