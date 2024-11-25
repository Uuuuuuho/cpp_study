// 직전 예제에서는 Object가 template class가 아니였음.
template <typename T>
struct Object {
    using type = int;

    template <typename U>
    void mf() {}
};

template <typename T>
void foo() {
    // Object<int>::type t1; // error. typename 
    typename Object<T>::type t1;

    // Object<int> obj1;
    Object<T> obj1; // 멤버를 꺼낸 것은 아님. 객체만 생성함.
    obj1.mf<int>(); // 객체 생성에는 template을 사용해놓고 인스턴스에서는 int를 사용하기 때문에 error.
    obj1.template mf<int>(); // 표준에 따라 template을 붙여줌.
}

int main() {
    foo<int>();
}