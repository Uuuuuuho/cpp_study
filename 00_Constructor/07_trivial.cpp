#include <iostream>
#include <type_traits>

class A
{
public:
    // Explanation: when is a default constructor "trivial"?
    // 1. It must be implicitly declared by the compiler (i.e. you didn't
    //   provide a user-defined default constructor).
    // 2. The class must not have virtual base classes or virtual functions
    //   that require runtime setup (vptr initialization typically makes it
    //   non-trivial).
    // 3. All non-static data members and direct base classes must themselves
    //   have trivial default constructors.
    // If these conditions hold the default construction requires no
    // non-trivial work and can be optimized by the compiler (often
    // implemented as zero-initialized or plain memory copying in some
    // contexts).
    //
    // In this example: A has a user-declared (non-virtual) member function
    // only, so it meets the simple conditions and is trivially
    // constructible. If you uncomment `virtual void foo(){}` the class
    // becomes polymorphic and typically is NOT trivially constructible.
    // virtual void foo(){}    // would make is_trivially_constructible false
    void foo(){}    // True (no virtuals, no user-defined ctor)
};

int main(){
    // The trait prints 1 if A's default constructor is trivial, 0 otherwise.
    // Trivial default constructors are important for low-level/optimizing
    // code (POD-like behavior, fast allocation, memcpyable initialization).
    std::cout << std::is_trivially_constructible<A>::value;
}