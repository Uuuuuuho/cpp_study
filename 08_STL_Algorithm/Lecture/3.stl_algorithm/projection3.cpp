#include <vector>
#include <algorithm>
#include <iostream>

/* 
projection 개념은
→ 알고리즘의 컨테이너 버전뿐 아니라 반복자 버전도 사용가능.
→ find 뿐만 아니라 find_if에도 사용가능
→ find 뿐만 아니라 대부분의 알고리즘이 지원

*/

struct Point 
{
	int x, y;
	int get_y() const { return y;}
};
int main()
{
	namespace rgs = std::ranges;
	std::vector<Point> v{{1,1},{2,2},{3,3},{4,4}};

	auto ret1 = rgs::find(v, 3, &Point::y);	

	auto ret2 = rgs::find(v.begin(),v.end(),3, &Point::y);

	auto ret3 = rgs::find_if(v,
							 [](int n){return n == 1;}, 
							 &Point::y);
}