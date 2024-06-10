// 8_완벽한전달활용
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// 1. 이름있는 객체를 만들어서 넣기
//	Point pt(1, 2);
//	v.push_back(pt);

	// 2. 임시객체를 만들어서 넣기
	// v.push_back( Point(1, 2) );


	// 3.핵심!!! 객체를 만들어서 전달하지 말고
	// 객체를 만들기 위한 생성자 인자를 전달하자!!

	v.emplace_back(1, 2);
			// 이 함수 안에서 버퍼에 직접 "new Point(1,2)"로 생성
	
	// main				emplace_back()	     Point(int a, int b)
	// Point(1, 2) ===========================> 직접 전달
	// emplace(1,2) ======> 받은것을 생성자로전달 ====> 

	std::cout << "-----" << std::endl;
}
// 1. vector<int> v;   // primitive type 보관 하므로
//						  push_xxx(), emplace_xxx() 동일
// 2. vector<Point> v;  // 사용자 정의 타입 보관
//	 push_back() => emplace_back()
//   insert()    => emplace()