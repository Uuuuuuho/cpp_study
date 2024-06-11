/* 
ADL (Argument Dependent Lookup)이란?

→ 함수를 찾을 때 인자가 속해있는 이름 공간은 자동으로 검색한다는 문법

ADL이 필요한 이유

→ 특정 namespace 안에 있는 객체 등에 연산자 재정의 문법 등을 사용하려면 ADL 개념이 필요하다.
*/

namespace Graphics
{
	struct Point
	{
		int x, y;
	};
	void draw_pixel(const Point& pt) {}
};

int main()
{
	Graphics::Point pt{1, 2};

	Graphics::draw_pixel(pt);

	draw_pixel(pt); // ok
}