#include <iostream>
#include <thread>
#include <atomic>

struct Point { int x, y; };         // 64-bit
struct Point3D { int x, y, z; };    // 96-bit

std::atomic<int>        a1;     // int 타입을 "atomic"하게
std::atomic<Point>      a2;     // Point 타입을 "atomic"하게
std::atomic<Point3D>    a3;     // Point3D 타입을 "atomic"하게

int main()
{
    ++a1; 
    int n = a1.load();      // CPU instruction으로 thread safe하게 동작함.

    Point pt = a2.load();   // 64-bit까지는 atomic load ISA supported.
    // Point3D pt2 = a3.load();

    std::cout << a1.is_lock_free() << std::endl;
    std::cout << a2.is_lock_free() << std::endl;
    // std::cout << a3.is_lock_free() << std::endl;    // undefined 96-bit is_lock_free()
}

