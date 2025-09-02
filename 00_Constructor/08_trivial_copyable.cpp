#include <iostream>
#include <type_traits>

struct Point
{
    int x = 0;
    int y = 0;
    // Having a virtual function usually makes the class non-trivially
    // copyable because a vptr must be set up; therefore memcpy is not
    // safe for such a type. This comment intentionally keeps the
    // example simple but demonstrates why the trait matters.
    virtual void foo(){} // makes Point non-trivially copyable
};
template<class T>
void copy_type(T* dst, T* src, std::size_t sz)
{
    // We choose between a raw memory copy (fast) and element-wise copy via
    // copy constructors. Important notes:
    // - memcpy/bitwise copy is only safe for types that are trivially
    //   copyable (no user-defined copy/move ctors, no virtuals, no
    //   non-trivial members). The standard trait that expresses this is
    //   `std::is_trivially_copyable`. This example uses
    //   `is_trivially_copy_constructible_v` as a simple proxy, but prefer
    //   `is_trivially_copyable` when deciding to use memcpy in real code.
    // - The destination must point to suitably allocated, and for the
    //   non-trivial branch, uninitialized storage where placement-new can be
    //   used to construct objects.
    // - If you use placement-new you must also call destructors manually
    //   when cleaning up.
    if constexpr (std::is_trivially_copy_constructible_v<T>)
    {
        std::cout << "using memcpy" << std::endl;
        memcpy(dst,src,sizeof(T)*sz);
    }
    else
    {
        std::cout << "using copy ctor" << std::endl;
        while(sz--)
        {
            new(dst) T(*src);
            // After placement-new we must advance pointers to the next
            // element. Note: original code decremented pointers; here we
            // advance them forward so the loop constructs elements in
            // increasing order.
            ++dst; ++src;
        }
    }
}

int main()
{
    Point arr1[5];
    // Point arr2[5];
    // Allocate memory for arr2 but not call constructors
    Point* arr2 = static_cast<Point*>(operator new(sizeof(Point)*5));
    copy_type(arr1, arr2, 5);
}