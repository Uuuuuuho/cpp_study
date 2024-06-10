#include <iostream>
#include "01_stack2.h"

int main()
{
    stackType<int> st;
    st.initializeStack();
    st.push(3);
    std::cout << st.top() << std::endl;
    std::cout << st.isEmptyStack() << std::endl;
    st.pop();
}