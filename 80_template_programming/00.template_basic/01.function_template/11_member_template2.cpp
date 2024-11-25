template<typename T>
class Point
{
	T x, y;
public:
	Point(const T& a, const T& b) : x(a), y(b) {}

    // 둘 다 같은 의미이고, 맞는 문법임.
    // Point(const Point& p) {}
    // 문제는 인자로 받는 타입이 현재 인스턴스의 타입과 동일해야함.
    Point(const Point<T>& p) {}
    Point(const Point<int>& p) {} // 인자의 타입이 int인 경우만 복사 생성자 no error.

    /* Coercion by member template 
     * T가 U로 복사(대입) 가능하다면 Point<T>도 Point<U>로 복사(대입) 가능해야한다.
     */
    template<typename U>
    Point(const Point<U>& p) : x(p.x), y(p.y) {} // Generic 복사생성자. 임의 타입의 인자를 받아서 복사 생성자를 실행시킬 수 있음.

    template<typename> friend class Point;
};

int main()
{
	Point<int> p1(1, 2);  // ok
	Point<int> p2 = p1;   // 복사생성자. ok

	Point<double> p3 = p1;// ?? 

}