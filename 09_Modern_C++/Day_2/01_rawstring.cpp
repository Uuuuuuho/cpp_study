#include <iostream>
#include <string>

int main()
{
	// "\" : 특수 문자로 취급
	std::string s1 = "\\\\.\\pipe\\server";

	// raw string : "\" 를 특수 문자로 취급하지 말라
	// 시작토큰 : "(
	// 종료토큰 : )"
	std::string s2 = R"(\\.\pipe\server)";

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	// 1. " 또는 ' 등을 표기하려면 => 그냥 표기하면 됩니다.
	std::string s3 = R"(\\.\pi"pe\server)";

	// 2. )" 를 표기하려면 어떻게 하나요 ?
	// => 시작과 끝을 사용자가 변경할수 있습니다.
	// => 아래 코드는 "***( 가 시작   )***" 가 종료
	std::string s4 = R"***(\\.\pi)"pe\server)***";
}