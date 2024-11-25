#include <string>
#include <type_traits>

template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

    // type conversion이 가능한 경우만 동작할 수 있도록 하는 "requires std::is_convertible_v"
    template<typename U> requires std::is_convertible_v<T, T>
    Point(const Point<U>& p) : x(p.x), y(p.y) {} // Generic 복사생성자. 임의 타입의 인자를 받아서 복사 생성자를 실행시킬 수 있음.

    template<typename> friend class Point;
};

int main() {
    Point<std::string> p1("1", "2");

    Point<int> p2 = p1; // std::string을 int로 convert 할 수 없다는 error가 발생함.
}