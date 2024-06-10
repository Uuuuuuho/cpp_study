#ifndef FOO
#define FOO

int foo();
template <typename T>
struct test{
    // int mem_var;
    T mem_var;
    test(T data);
    ~test();
};

template<typename T>
test<T>::test(T data)
{
    mem_var = data;
}

template<typename T>
test<T>::~test()
{
    
}
#endif