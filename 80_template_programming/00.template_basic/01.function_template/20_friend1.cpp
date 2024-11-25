#include <iostream>

template <typename T>
class Point
{
	T x, y;
public:
	Point(T a, T b) : x(a), y(b) {}

    // "friend" 키워드는 외부 클래스가 private에 접근을 허용하기 위한 것.
	friend std::ostream& operator<<(std::ostream& os, const Point& pt);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& pt) {
// Point<T>에 에러가 발생함.
	std::cout << pt.x << ", " << pt.y << std::endl;
	return os;
}

int main()
{
	Point<int> p(1,2);

	std::cout << p << std::endl;
}