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
    // create a unique_ptr owning a newly created A
    // prefer std::make_unique<A>() in production code
    std::unique_ptr<A> pa(new A());
    std::cout << "pa : ";
    pa->some();

    // pb에 소유권을 이전
    // unique_ptr cannot be copied (copy ctor is deleted). It can only be moved.
    // std::move transfers ownership: after this, pa becomes null and pb owns the A.
    std::unique_ptr<A> pb = std::move(pa);
    std::cout << "pb : ";
    pb->some();
}

int main() { do_sth(); }
