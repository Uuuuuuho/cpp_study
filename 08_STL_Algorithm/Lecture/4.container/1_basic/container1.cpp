#include <vector>

/* STL 컨테이너 특징 #1
    "member type"이 있다.
    v.size()의 반환 타입은 어떤 타입일까?
    => STL의 실제 구현 환경에 따라 다를 수 있다.
    => C++ 표준에서는 각 컨테이너는
        "size_type"이라는 member type이 있어야하고
        "size() 함수는 size_type을 반환"한다.
*/

int main()
{
	std::vector v{1, 2, 3, 4};

	auto sz1 = v.size();  // 권장

	std::vector<int>::size_type sz2 = v.size(); 
}
