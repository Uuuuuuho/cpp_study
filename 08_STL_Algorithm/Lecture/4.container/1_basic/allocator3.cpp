#include <vector>
#include <iostream>

/* 핵심
    사용자 정의 allocator를 만들려면
        C++ 표준에서 요구하는 요구사항을 만족해야한다.
            cppreference.com 사이트
            첫 화면에서 name requirements 선택 후 
            allocator 항목 선택
    Allocator의 요구조건은 복잡하지만 대부분 optional
    Allocator의 최소 요구조건
        member type   value_type
        멤버 함수       allocate(), deallocate()
        생성자         디폴트 생성자, template 생성자
        비교 연산       ==, !=
*/

template<typename T>
class debug_alloc
{
public:
    using value_type = T;
    debug_alloc() = default;
    template<typename U> debug_alloc(debug_alloc<U>&) {}

    T* allocate(std::size_t sz)
    {
        void* ptr = malloc(sizeof(T) * sz);
        std::cout << "allocate: " << static_cast<void*>(ptr) << " " << sz << std::endl;
        return static_cast<T*>(ptr);
    }
    void deallocate(T* ptr, std::size_t sz)
    {
        std::cout << "deallocate: " << static_cast<void*>(ptr) << " " << sz << std::endl;
        free(ptr);
    }
};

template<typename T>
bool operator==(const debug_alloc<T>& a1, const debug_alloc<T>& a2){ return true; }

template<typename T>
bool operator!=(const debug_alloc<T>& a1, const debug_alloc<T>& a2){ return false; }

int main()
{
    std::vector<int, debug_alloc<int>> v{1,2,3,4};
    // std::vector<int> v{1,2,3,4};

    std::cout << "===========" << std::endl;

    v.resize(8);

    std::cout << "===========" << std::endl;
}