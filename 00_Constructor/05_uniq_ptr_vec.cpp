#include <iostream>
#include <memory>
#include <vector>

class A
{
private:
    /* data */
    int *data;
public:
    A(int i){
        std::cout << "Acquired resource!" << std::endl;
        data = new int[100];
        data[0] = i;
    }

    void some() { std::cout << "value : " << data[0] << std::endl; }
    ~A(){
        std::cout << "Freed resource!" << std::endl;
        delete[] data;
    }
};

int main() {
    std::vector<std::unique_ptr<A>> vec;

    // vec.push_back(std::unique_ptr<A>(new A(1))); 과 동일함.
    vec.emplace_back(new A(1)); // 'emplace_back' is done by perfect forwarding.

    vec.back()->some();
}

