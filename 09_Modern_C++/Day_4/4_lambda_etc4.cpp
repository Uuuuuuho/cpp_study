class CompilerGeneratedName
{
public:
	inline int operator()(int a, int b) const { return a + b; }

	// 함수 포인터로의 변환을 위해서 컴파일러가 아래 코드를 생성합니다.
	using PF = int(*)(int, int);

	static int helper(int a, int b) { return a + b; }

	operator PF() { return &CompilerGeneratedName::helper; }
};

int main()
{
	int(*f)(int, int) = CompilerGeneratedName();
						// 객체.operator 함수포인터() 


//	int(*f)(int, int) = [](int a, int b) {return a + b; };
						// class xxx{}; xxx();
}
