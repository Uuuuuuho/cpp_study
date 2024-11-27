#include <iostream>

struct vector1
{
    vector1(std::size_t size){}
};
struct vector2
{
    /* explicit 키워드는 컴파일러가 자동 형변환 코드를 생성하는 것을 막아주는 기능을 합니다.
     * 사용자가 원하지 않는 형변환이 일어나는 경우를 막기 위해서 사용할 수 있어요. (double → int 등) 
     */
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
    f2(10); // error. std::size_t로 타입을 명시적 변환하지 않았기 때문이에요.
    f3({}); // ok
    f4({}); // error. 
}