#include <iostream>
#include <type_traits>

class A
{
public:
    virtual void foo(){}    
};

int main(){
    std::cout << std::is_trivially_constructible<A>::value;
}