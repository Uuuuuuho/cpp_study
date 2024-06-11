/* 목표!
    컨테이너가 내부적으로 메모리를 할당/해지하는 방법을
    사용자가 변경할 수 있도록 하는 것

  Policy Base Design(단위 전략 디자인)
    - 클래스가 사용하는 다양한 정책을 템플릿 인자로
      변경할 수 있게 하는 디자인 기법
    - STL에서 많이 사용하는 기법

  allocator 개념
    - 메모리 할당/해지를 추상화한 클래스
    - 사용자가 만들 수 있고, C++표준이 제공하기도 한다.
    - 메모리 할당/해지를 위해 약속된 멤버 함수를 제공
        a.allocate()    메모리 할당
        a.deallocate(): 메모리 해지

  std::allocator
    - C++ 표준 메모리 할당기
    - 내부적으로는 "operator new(), operator delete()"를 사용
*/

template<typename T, typename Alloc = std::allocator<T>>
class vector
{
private:
    /* data */
    T* ptr;
    Alloc ax;
public:
    using size_type = std::size_t;

    void resize(size_type sz)
    {
        ptr = ax.allocate(sz);
        
        ax.deallocate(ptr, sz);
    }
};

int main()
{
    vector<int> v{1,2,3,4};
    v.resize(8);
}