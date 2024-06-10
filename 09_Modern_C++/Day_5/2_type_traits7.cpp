#include <iostream>

class Object
{
public:
	Object() {}
	Object(const Object&)     { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept { std::cout << "move" << std::endl; }
};


// std::move 원리(구현)
// T&  : lvalue 받겠다는 것
// T&& : lvalue, rvalue 를 모두 받겠다는것
template<typename T>
std::remove_reference_t<T>&&  mymove(T&& obj)
{
	// T&& 를 인자로 사용하면
	// lvalue(o3) 을 보냈을때 T=Object& 입니다.
	// 따라서 아래 코드는 static_cast<Object& &&>(obj) 이므로
	// rvalue 캐스팅이 아닌 lvalue 캐스팅이 됩니다.
	// 
	// return static_cast<T&&>(obj);

	// move 는 항상 rvalue 캐스팅 되어야 합니다.
	//return static_cast<T&&>(obj); // T 안에 & 가 있을수 있습니다.
	
	return static_cast<std::remove_reference_t<T>&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = std::move(o2);	// move
	Object o5 = mymove(o3);		// move
	Object o6 = mymove(Object()); // 안되야 할까요? 되야할까요?
}

