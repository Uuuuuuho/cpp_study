#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void draw_line(const Point& from, const Point& to) {}

// 인자로 받은 객체를 reset 하는 함수
void init(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
	Point p1(1, 1);
	Point p2(5, 5);
	
	draw_line(p1, p2);	// 이렇게 전달하면
						// p1, p2가 더이상 필요 없어도
						// {} 벗어날때 파괴 됩니다.
	
	// 함수의 인자로만 사용하려면 임시객체로 전달하는 것이 
	// 효율적입니다.
	draw_line(Point(1, 1), Point{ 5, 5 }); //() 또는 {}

	//---------------------
	init(p1);			// 객체를 만들어서 전달하는 것은
						// 논리적으로 맞다!!

	init(Point(0, 0));	// 즉시 파괴될 임시객체를 변경하는것은
						// 논리적으로 맞지 않습니다.
	// 그래서
	// const& 는 임시객체를 받을수 있고
	// non-const& 는 임시객체를 받을수 없습니다.


	std::cout << "-----" << std::endl;
}