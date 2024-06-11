
/* C++에서 메몰를 할당/해지하는 방법은 다양하다.
    - new/delete
    - malloc/free
    - 각 OS가 제공하는 system call 사용
    - memory polling 기술 사용

  vector의 resize 멤버 함수에서 "new/delete를 직접 사용"했다면
    - vector 사용자가 다른 방식으로 변경할 수 없음.
  STL container는 메모리의 할당/해지 방식을 사용자가
  교체할 수 있도록 "allocator 개념을 사용"하고 있음.

*/

template<typename T>
class vector
{
private:
    /* data */
    T* ptr;
    // ....
public:
    using size_type = std::size_t;

    void resize(size_type sz)
    {
        // 새롭게 메몰리를 할당해야 한다면 
        // 어떤 방법을 사용하는 것이 좋을까?
    }
    vector(/* args */);
    ~vector();
};

int main()
{
    vector<int> v{1,2,3,4};
    v.resize(8);
}