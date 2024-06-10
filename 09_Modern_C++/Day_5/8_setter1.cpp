// 8_setter1.cpp
// git 에서 복사해 오세요

#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&)     { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept { std::cout << "move" << std::endl; }
};
int main()
{
	Object o1;
	Object o2 = std::move(o1);	// ??

	// 핵심. 상수객체는 move 될수 없습니다.
	const Object o3;
	Object o4 = std::move(o3); // ??
			// static_cast<o3타입&&>(o3)
			// static_cast<o3타입&&>(o3)
}