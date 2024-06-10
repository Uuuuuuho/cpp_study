#include <iostream>
#include <type_traits>

/*  lvalue or rvalue investigation
    principle : decltype(exp) => return reference type if exp is lvalue.
*/
#define CHECK_VALUE_CATEGORY(...)   \
    if(std::is_lvalue_reference<decltype((__VA_ARGS__))>::value) \
        std::cout << "lvalue!" << std::endl;                     \
    else                                                         \
        std::cout << "rvalue!" << std::endl;

int main()
{
    int n = 0;

    (n = 20) = 10;

    using exp_type = decltype(n = 20);

    // if(std::is_lvalue_reference<exp_type>::value)
    // if(std::is_lvalue_reference<decltype(n = 20)>::value)
    // if(std::is_lvalue_reference<decltype(n)>::value)    /* Rule 1 */
    // if(std::is_lvalue_reference<decltype((n))>::value)  /* Rule 2 */
    //     std::cout << "lvalue!" << std::endl;
    // else
    //     std::cout << "rvalue!" << std::endl;

    CHECK_VALUE_CATEGORY(n);        /* lvalue! */
    CHECK_VALUE_CATEGORY(3);        /* rvalue! */
    CHECK_VALUE_CATEGORY(++n);      /* lvalue! */
    CHECK_VALUE_CATEGORY(n++);      /* rvalue! */
    CHECK_VALUE_CATEGORY(n + n);    /* rvalue! */
    CHECK_VALUE_CATEGORY(n = 20);   /* lvalue! */

    CHECK_VALUE_CATEGORY("hello");  /* lvalue! */
        /*  string literal is categorized as lvalue. 
            "hello" requires memory allocation.
        */
}
