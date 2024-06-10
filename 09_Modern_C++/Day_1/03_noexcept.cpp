#include <new>
#include <iostream>

void foo() noexcept
{

}

void goo()
{
    if (1)
        throw std::bad_alloc();
}

int main()
{
    /* 
        noexcept(function call) : true if no exception in function
            Compiler investigation in compile time.
            This does not call function. Just investigate the function by declaration.
            Investigate if there is 'noexcept' in function declaration.
    */
   bool b1 = noexcept(goo()); /* false */
   bool b2 = noexcept(foo());
   std::cout << b1 << " " << b2 << std::endl;
}

/* 
    1. Why need to noitfy of function exception to compiler?
        For better compiler optimization.
    2. Why need to investigate exceptions?
        For better code implementation.
    3. If 'noexcept' is attached, but what if there is an exception?
        Abnormal exception fault.
        Must use 'noexception' when there is never exception.
        It is very difficult.
*/