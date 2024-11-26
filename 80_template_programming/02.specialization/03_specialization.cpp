#include <iostream>

template <typename T1, typename T2 = short>
struct Object {
    static void print() {
        std::cout << typeid(T1).name() << ", "
                  << typeid(T2).name() << std::endl;
    }
};

/* speicalization partial specialization을 만들때는 "default parameter 표기하지 않는다." 
 * 표기하지 않아도 "primary template의 default 값을 사용"하게 된다.
 */
template <typename T1, typename T2>
struct Object {
    static void print() {
        std::cout << typeid(T1).name() << ", "
                  << typeid(T2).name() << std::endl;
    }
};
