// C++20 coroutine 이야기

#include <iostream>

/*  서브루틴 : 함수가 종료된 후에 호출자로 반환
		코루틴 : 함수중간에 호출자로 복귀
						다음 호출시, 이전에 중단된 지점부터 다시 실행.
		요즘 대부분의 언어가 지원 : C#, python, java 등, 사용법도 쉬움.
		C++20부터 지원 : 아주 복잡하게 되어있습니다.
*/

// 아래 foo는 코루틴이 아닙니다. 서브루틴 입니다.
void foo()
{
	std::cout << "foo 1" << std::endl;
	std::cout << "foo 2" << std::endl;
}

int main()
{
	foo();
}
