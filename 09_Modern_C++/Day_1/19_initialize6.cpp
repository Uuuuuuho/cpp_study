#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	hoo("hello");	// 문맥이 이상하지 않습니다.
					// 되어야 합니다... 됩니다.

	std::string s1("hello");	// ok
	std::string s2 = "hello";	// ok
						// string(const char*) 생성자는
						// explicit 가 아닙니다

	goo(10);	// hoo(10) 등으로 코딩하려다가 실수!!!
				// 안되는것이 좋습니다. 안됩니다.
	std::vector<int> v1(10);	// ok
	std::vector<int> v2 = 10;	// error
					// vector(int) 생성자는 explicit 라는 의미
}
// 결론 : 생성자를 만들때 "explicit"를 표기할지 말지를 잘판단하세요
//  요즘은 "붙이는 경우가 많은데", 
//  string 같은 경우는 붙이면 불편합니다.
//  하지만 아래 같은 의견도 있습니다.
//  => hoo("hello"); 에러 나오게 하고
//  => hoo("hello"s); 이 코드만 되도록 하자.

// 복사초기화 막는 방법으로 다른 방법도 사용하지 않나요
// => 예전에 사용하던 방법 있습니다. 끝날때 소개.. 
