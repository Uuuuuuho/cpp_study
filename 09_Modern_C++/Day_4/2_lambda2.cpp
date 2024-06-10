#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

    /*  Compiler generates code below. 
        i.e. Compiler translate the lambda expression into function object.
    */
    class CompilerGeneratedName
    {
    public:
        inline auto operator()(int a, int b) const{
            return a < b;
        }
    };

    std::sort(v.begin(), v.end(), CompilerGeneratedName());

    /*  람다표현식은 : 컴파일러가 만든 함수객체를 "임시객체" 형태로 생성하는 코드. 
        따라서 람다표현식은 rvalue임.
    */
}
