#include <iostream>
#include <memory>

class A
{
private:
    /* data */
    int *data;

public:
    A(/* args */){
        std::cout << "Resource acquired!" << std::endl;
        data = new int[100];
    }

    void some() { std::cout << "same as normal ptr" << std::endl; }
    ~A(){
        std::cout << "Resource freed!" << std::endl;
        delete[] data;
    }
};

void do_sth() {
    std::unique_ptr<A> pa(new A());
    std::cout << "pa : ";
    pa->some();

    // pb에 소유권을 이전
    std::unique_ptr<A> pb = std::move(pa);
    std::cout << "pb : ";
    pb->some();
}

int main() { do_sth(); }
