#include <iostream>

struct vector1
{
    vector1(std::size_t size){}
};
struct vector2
{
    explicit vector2(std::size_t size){}
};
struct empty1 {empty1() = default;};
struct empty2 {explicit empty2() = default;};

void f1(vector1 v){}
void f2(vector2 v){}
void f3(empty1 e){}
void f4(empty2 e){}

int main(){
    f1(10); // ok
    f2(10); // error
    f3({}); // ok
    f4({}); // error
}