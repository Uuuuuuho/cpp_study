#include <iostream>
#include <type_traits>

struct Point
{
    int x = 0;
    int y = 0;
    virtual void foo(){} // for nontrivial constructor
};
template<typename T> 
std::enable_if_t<std::is_trivially_copy_constructible_v<T>>
copy_type(T* dst, T* src, std::size_t sz)
{
    std::cout << "using memcpy" << std::endl;
    memcpy(dst, src, sizeof(T)*sz);
}

template<typename T>
std::enable_if_t<!std::is_trivially_constructible_v<T>>
copy_type(T* dst, T* src, std::size_t sz)
{
    std::cout << "using copy ctor" << std::endl;
    while(sz--)
    {
        new(dst) T(*src);
        --dst, --src;
    }
}

int main()
{
    Point arr1[5];
    // Point arr2[5];
    Point* arr2 = static_cast<Point*>(operator new(sizeof(Point)*5));
    copy_type(arr1, arr2, 5);

    int arr3[5];
    int arr4[5];
    copy_type(arr3, arr4, 5);
}