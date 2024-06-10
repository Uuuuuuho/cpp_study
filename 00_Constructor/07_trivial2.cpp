#include <iostream>
#include <type_traits>

struct TrivialDefaultCtor   // true
{
    int data;
};
struct NonTrivialDefaultCtor
{
    int data;
    NonTrivialDefaultCtor(){}
};
struct Type1
{
    // 컴파일러가 디폴트 생성자 제공안함. - false
    Type1(int a){}
};
struct Type2
{
    Type2(){} // false
    Type2(int a){}
};
struct Type3
{
    Type3() = default; // true
    Type3(int a){}
};
struct Type4 // false
{
    int data = 0; // initialize하기 때문에 false임.
    // int data;
    // Type(): data(0){}
};
struct Type5 // false
{
    int data;
    virtual void foo(){}
};
struct Type6 // false
{
    int data1;
    NonTrivialDefaultCtor data2;
};
struct Type7 // true
{
    int data1;
    TrivialDefaultCtor data2;
    // Type7(): data2(){} //컴파일러가 추가하는 코드
};
struct Type8 : public NonTrivialDefaultCtor // false
{
    int data;
};
struct Type9 : public TrivialDefaultCtor // true
{
    int data;
};
struct Type10 : public virtual TrivialDefaultCtor // false
{
};
struct Type11 // false
{
    Type11() = delete;
};
struct Type12 // false
{
    int &ref; // 참조멤버가 있으면 디폴트 생성자는 delete됨.
};
// Type12 t;
struct Type13 // false
{
    const int c;
};
template<class T> void check()
{
    std::cout << typeid(T).name() << " : ";
    std::cout << std::boolalpha;
    std::cout << std::is_trivially_default_constructible_v<T> << std::endl;
}
int main()
{
    check<TrivialDefaultCtor>();    // true
    check<NonTrivialDefaultCtor>(); // false
    check<Type1>();
    check<Type2>();
    check<Type3>();
    check<Type4>();
    check<Type5>();
    check<Type6>();
    check<Type7>();
    check<Type8>();
    check<Type9>();
    check<Type10>();
    check<Type11>();
    check<Type12>();
    check<Type13>();
}