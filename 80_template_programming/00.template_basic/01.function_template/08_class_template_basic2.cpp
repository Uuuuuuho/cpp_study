template<typename T>
class Object
{
public:
	void mf1(int n) {}
	void mf2(T   n) {} // 이건 function template이 아니라 class template임.
    // class template의 member function인 것.

	template<typename U> 
	void mf3(U n); // member function template. 함수 자체가 템플릿.
};

// member function template의 외부 구현 모양은 복잡해짐.
template <typename T> template <typename U>
void Object<T>::mf3(U n) {

}

int main()
{
	Object<int>    obj1;
	Object<double> obj2;

	obj1.mf1(3);
	obj2.mf1(3);

	obj1.mf2(3);
	obj2.mf2(3.4);

	obj1.mf3(3);
	obj1.mf3(3.4);
}