#include <iostream>
#include <atomic>

/*  사용자가 만들지 않고, 컴파일러가 제공하는 복사 생성자를
    trivial(자명)하다고 합니다.
    
    atomic<T>에서 T의 조건은
    복사 생성자, 대입연산자, move 생성자, move 대입연산자가 trivial 해야합니다.
    사용자가 만들면 안된다는 의미.
*/
struct Point
{
    int x, y;
    Point() = default;

    // 복사생성자를 사용자가 만든 경우
    Point(const Point& pt) : x(pt.x), y(pt.y){};
};

std::atomic<Point> pt;

int main()
{
    Point ret = pt.load();
}

