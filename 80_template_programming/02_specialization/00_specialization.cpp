#include <iostream>

template <typename T> class Vector {
    T* ptr;
    std::size_t size;
public:
    Vector(std::size_t sz) : size(sz) {
        ptr = new T[sz];
    }
    ~Vector() { delete[] ptr; }
};

template<> class Vector<bool> {
    int* ptr;
    std::size_t size;
public:
    Vector(std::size_t sz) : size(sz) {
        ptr = new[(sz/32) + 1];
    }
    ~Vector() { delete[] ptr; }
}

// Typename이 pointer인 경우 아래의 인스턴스를 생성함.
// Partial specialization
template<typename T> class Vector<T*> {
    T* ptr;
    std::size_t size;
public:
    Vector(std::size_t sz) : size(sz) {
        ptr = new T[sz];
    }
    ~Vector() { delete[] ptr; }
}

int main() {
    Vector<int>     v1(5);
    Vector<double>  v2(5);
    Vecotr<bool>    v3(5);
}