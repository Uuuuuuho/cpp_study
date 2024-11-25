#include <iostream>

template <typename T>
class Point
{
	T x, y;
public:
	Point(T a, T b) : x(a), y(b) {}

	/* 해결책 2. 구현체를 직접 넣는다.
	 * 일반함수가 선택되지만 구현체가 없던 문제를 구현체를 넣어서 해결하는 방식.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt) {
		std::cout << pt.x << ", " << pt.y << std::endl;
		return os;
	}
};

int main()
{
	Point<int> p(1,2);

	std::cout << p << std::endl;
}