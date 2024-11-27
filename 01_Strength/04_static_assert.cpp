#include <iostream>

struct Object;
void deleter(Object* p)
{
    // 데이터의 유효성을 컴파일 타임에 확인하기 위한 매크로입니다.
    static_assert(sizeof(Object) > 0,
                    "error, can't delete imcomplete type");
    delete p;
}
struct Object
{
    Object()    {std::cout << "Object()" << std::endl;}
    ~Object()  {std::cout << "~Object()" << std::endl;}
};

int main()
{
    Object *p = new Object();
    deleter(p);
}