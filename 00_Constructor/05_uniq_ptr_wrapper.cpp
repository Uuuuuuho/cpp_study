#include <iostream>
#include <memory>

class A
{
private:
    /* data */
    int* data;
public:
    A(/* args */);
    void some() { std::cout << "same as normal pointer" << std::endl; }
    void do_sth(int a){
            std::cout << "do something" << std::endl;
            data[0] = a;
    }
    ~A();
};

A::A(/* args */)
{
    std::cout << "Acquired resource!" << std::endl;
    data = new int[100];
}

A::~A()
{
    std::cout << "Freed resource!" << std::endl;
    delete[] data;
}

void do_something(A* ptr) { ptr->do_sth(3); }
/* 
    아래 예시에서 'ptr'은 레퍼런스이기 때문에 'do_something_wrong'이 종료되면서
    'pa'가 가리키는 객체를 파괴하진 않지만, 'pa'가 유일하게 소유하는 객체는 
    'ptr'을 통해서도 소유할 수 있게됨.
    즉, 'unique_ptr은 소유권을 의미한다는 원칙에 위배됨.
    따라서 위와 같이 포인터의 주소를 넘겨주는 것이 좋음.
*/
void do_something_wrong(std::unique_ptr<A>& ptr) { ptr->do_sth(3); }


int main() {
    std::unique_ptr<A> pa(new A());
    do_something(pa.get());
}