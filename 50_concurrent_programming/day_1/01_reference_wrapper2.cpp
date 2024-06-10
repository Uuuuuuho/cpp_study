#include <iostream>

// C++ 표준의 reference_wrapper 의 원리를 생각해 봅시다.
template<typename T>
class reference_wrapper
{
	T* pobj;
public:
	reference_wrapper(T& r) : pobj(&r) {}

	operator T& () { return *pobj; }

  T& get() const{ return *pobj; }
};

int main()
{
	int v1 = 10, v2 = 20;

	reference_wrapper<int> r1(v1); 
	reference_wrapper<int> r2(v2); 

	r1 = r2;	// r1.operator=(r2) 인데, 컴파일러가 디폴트 대입연산자 제공
				// => 기본 구현은 모든 멤버를 얕은 복사
				
	// reference_wrapper 는 "raw reference" 와 호환 되어야 합니다
	int& r3 = r1;	// r1.operator int&() 가 필요 합니다


	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
	std::cout << r2.get() << std::endl;
	std::cout << &v2 << std::endl;
	std::cout << &(r2.get()) << std::endl;
}
