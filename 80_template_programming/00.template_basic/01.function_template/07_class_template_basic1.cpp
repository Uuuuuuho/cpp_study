#include <iostream>

template <typename T>
class Vector {
    T* ptr;
    std::size_t size;
public:
    Vector(std::size_t sz) : size(sz) {
        ptr = new T[sz];
    }
    ~Vector() { delete[] ptr; }

    T& operator[](std::size_t idx) { return ptr[idx]; }

    Vector(const Vector&) = delete;
    // Vector(const Vector<T>&) = delete; // 이렇게 작성하는게 정확하지만 "클래스 내부에서 멤버함수"는 위와 같이 사용해도됨.
};

// void fn(const Vector<int>& v) {} // error
void fn(const Vector<int>& v) {} // ok

int main() {
    // Vector(10); // error
    Vector<int> v(10); // ok
    v[0] = 10;
    fn(v);
}