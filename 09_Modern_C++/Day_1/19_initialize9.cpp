#include <iostream>
#include <initializer_list>

void foo(std::initializer_list<int> e)
{
    /* 
        Take tiny arguments.
    */
}
int main()
{
    /* 
        std::initializer_list<int>
        => Make memory of every init value.
        => Most compiler allocate them on stack.
        => s itsetf is "2 pointers" or "pointer+length".
    */
	std::initializer_list<int> s = { 1,2,3,4,5 };

    auto p1 = s.begin();
    auto p2 = s.end();

    // *p1 = 10; /* Error. Read only. */

    /* 
        Why need?
        => To use it for function argument.
        => "able to pass variadic length" for integer type into 'foo'.
    */
   foo(s);
   foo({1,2,3});
   foo({1,2,3,4,5});
}


