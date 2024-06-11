#include <vector>
#include <algorithm>
#include "../cmc.h"

/* 
std::remove	기본형
std::remove_if	조건자 버전
std::remove_copy	복사 버전
std::remove_copy_if	복사 조건자 버전
*/

int main()
{
	std::vector v1{1, 3, 1, 3, 1, 3, 10, 3, 9, 3};
	std::vector v2{1, 3, 1, 3, 1, 3, 10, 3, 9, 3};
	std::vector v3{0, 0, 0, 0, 0, 0, 0,  0, 0, 0};

	namespace rgs = std::ranges;

	auto ret1 = rgs::remove(v1.begin(), 
							std::next(v1.begin(), 7), 3);

	std::println("{}", typeid(ret1).name()); // subrange
    show(v1);
	show(ret1.begin(), ret1.end());



	auto ret2 = rgs::remove_copy(v2.begin(), 
								 std::next(v2.begin(), 7),
								 v3.begin(), 3);

	std::println("{}", typeid(ret2).name()); // in_out_result
	show(v2.begin(), ret2.in);
	show(v3.begin(), ret2.out);
}
