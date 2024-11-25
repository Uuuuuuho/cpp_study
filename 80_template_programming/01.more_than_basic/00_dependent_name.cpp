struct Object
{
    using type = int;

    static constexpr int value = 10;

    template<typename T> struct rebind {

    };

    // template <typename T>
    // void foo(T obj) {
    //     // Object::value * 10; // 10 * 10
    //     // Object::type * p1; // int* p1
    //     // Object::rebind<int> a;
    // }
};

template <typename T>
void foo(T obj) {

    /* Object의 내부변수를 사용하면 아래와 같이 작성하면 되지만
     * template을 아래와 같이 사용하면 대상이 값인지 타입인지 컴파일러에게 확인이 어려움.
     */
    // Object::value * 10; // 10 * 10
    // Object::type * p1; // int* p1
    // Object::rebind<int> a;

    /* Dependent name
     * Template paramter에 의존적인 이름.
     * non-type     아무것도 붙이지 않아도 된다.
     * type         typename을 붙여야한다.
     * template     template을 붙여야한다.
     */
    T::value * 10; // 10 * 10. non-type
    typename T::type* p1; // int* p1
    typename T::template rebind<int> a; //

}

int main() {
    Object obj;
    foo(obj);
}