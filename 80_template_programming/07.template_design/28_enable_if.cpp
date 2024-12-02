#include <type_traits>

class Animal {};
class Dog : public Animal {};

template <typename T>
class smart_ptr {
    T* obj;
public:
    smart_ptr(T* p = nullptr) : obj { p } {}

    template <typename U,
              // 기존에 에러 메시지가 복잡하게 나오던 것을 convertibility에 따라 
              // specialization을 적용할 것인지 판단하도록 코드를 아래와 같이 추가했습니다.
              // 에러 메시지가 훨씬 명확해지는 효과를 볼 수 있습니다.
              typename X = std::enable_if_t< std::is_convertible_v<U*, T*> > >
    smart_ptr(const smart_ptr<U>& other): 
        obj{other.obj} {}

    template <typename> friend class smart_ptr;
};

int main() {
    smart_ptr<Dog>      sp1{new Dog};
    smart_ptr<Animal>   sp2 = sp1;

    smart_ptr<int>      sp3 = sp1;
}

/* 생성자에 std::enable_if를 적용하려면
 *  생성자는 반환 타입을 표기하지 않는다.
 *  함수 인자 또는 template 인자로 표기
 *  template 인자를 사용하는 것이 가독성이 좋다.
 */