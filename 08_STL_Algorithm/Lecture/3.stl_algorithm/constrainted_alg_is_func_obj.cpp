/* 
C++98 알고리즘	  std 이름 공간
                인자로 반복자만 사용가능
                함수(템플릿)으로 구현

C++20 알고리즘	  std::ranges 이름 공간
                인자로 반복자 뿐 아니라 컨테이너도 전달가능
                보다 많은 정보를 담은 반환값
                함수가 아닌 함수객체로 구현
*/

#include <algorithm>

int main()
{
	auto ret1 = std::max(1, 2);
	auto ret2 = std::ranges::max(1, 2);
	auto ret3 = std::ranges::max.operator()(1,2);
}