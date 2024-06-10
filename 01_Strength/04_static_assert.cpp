#include <iostream>

struct Object;
void deleter(Object* p)
{
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