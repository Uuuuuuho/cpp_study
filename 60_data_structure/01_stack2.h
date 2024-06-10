#include "01_stack2_ADT.h"
template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>
    &operator=(const stackType<Type>&); //Overload the assignment operator.
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const Type& newItem);
    Type top() const;
    void pop();
    stackType(int stackSize = 100); //Constructor
    stackType(const stackType<Type>& otherStack); //Copy constructor
    ~stackType(); //Destructor
private:
    int maxStackSize;   //variable to store the maximum stack size 
    int stackTop;       //variable to point to the top of the stack 
    Type *list;         //pointer to the array that holds the stack elements
    void copyStack(const stackType<Type>& otherStack); 
};

template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return (stackTop==0);
}

template<class Type>
bool stackType<Type>::isFullStack() const
{
    return(stackTop==maxStackSize);
}

template<class Type>
void stackType<Type>::push(const Type& newItem)
{
    if(!isFullStack())
    {
        list[stackTop++] = newItem;
    }
    else std::cout << "Cannot add to a full stack" << std::endl;
}

template<class Type>
Type stackType<Type>::top() const
{
    // assert(stackTop!=0);
    return list[stackTop - 1];
}

template<class Type>
void stackType<Type>::pop()
{
    if(!isEmptyStack()) stackTop--;
    else                std::cout << "Cannot remove from an empty stack." << std::endl;
}

template<class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];
    
    for(int i = 0; i < stackTop; i++)
        list[i] = otherStack.list[i];
}
template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        std::cout   << "Size of the array to hold the stack must " 
                    << "be positive."    
                    << std::endl;
        std::cout   << "Creating an array of size 100." << std::endl; 
        maxStackSize = 100;
    }
    else
    maxStackSize = stackSize;   //set the stack size to
                                //the value specified by 
                                //the parameter stackSize
    stackTop    =    0;         //set stackTop to 0
    list = new Type[maxStackSize]; 
    //create the array to
    //hold the stack elements
}

template<class Type>
stackType<Type>::~stackType() //destructor
{
    delete [] list; //deallocate the memory occupied
                    //by the array
}

template<class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = NULL;
    copyStack(otherStack);
}

template<class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack)
{
    if(this != &otherStack) // avlid self-copy
        copyStack(otherStack);
    return *this;
}