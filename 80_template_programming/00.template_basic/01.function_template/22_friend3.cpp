#include <iostream>

template <typename T>
class Point
{
	T x, y;
public:
	Point(T a, T b) : x(a), y(b) {}

	/* 인스턴스화 순간에 template type이 결정됨 
	 * → template function이 아니라 일반 함수가 되는 것. 
	 * 일반함수와 template functino 중 일반함수의 우선순위가 높기 때문에 아래의 함수가 선택됨.
	 * 그러나 선언만 있고 구현체가 없어서 링킹단계에서 undefined error가 발생함.
	 */
	// friend std::ostream& operator<<(std::ostream& os, const Point& pt);
	// friend std::ostream& operator<<(std::ostream& os, const Point<T>& pt);

	/* 위의 friend 일반함수 선언 문제를 극복하기 위해 friend 멤버함수의 template을 별도로 정의함.
	 * 그런데 int 인스턴스가 int, double, long 모든 타입과 friend 관게를 맺게됨.
	 * 에러는 아니지만 좋은 코드는 아님.
	 */
	template <typename U>
	friend std::ostream& operator<<(std::ostream& os, const Point<U>& pt);
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