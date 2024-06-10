#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

/* 핵심 개념
    1. iterator category tag
        <iterator> header
        반복자의 5가지 category를 나타내는 타입. empty class로 제공
        C++17에서 추가된 contiguous iterator는 별도의 tag가 제공되지 않음
    2. "iterator_category" member type
        모든 반복자는 내부적으로 "iterator_category"라는 이름의 "member type"을 제공해야함
        반복자 카테고리에 따라서 다른 알고리즘이 필요한 경우, "iterator_category" 
            member type을 활용한 "tag dispatching" 기법을 사용함
*/
namespace tag // STL 내부에 tag가 이런식으로 구분되어 있음
{
struct input_iterator_tag {}; // empty class
struct output_iterator_tag {}; // empty class
struct forward_iterator_tag
    : public input_iterator_tag {};
struct bidirectional_iterator_tag
    : public forward_iterator_tag {};
struct random_access_iterator_tag
    : public bidirectional_iterator_tag {};

template<typename T> class vector_iterator{
public:
    using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator{
public:
    using iterator_category = bidirectional_iterator_tag;
};
} // namespace tag

template<typename T>
void eadvance_imp(T& p, int n,
              random_access_iterator_tag){ // 3번째 인자의 객체 종류만 가지고 오버로딩을 따지기 위함
    std::cout << "random iterator" << std::endl;
    p = p + 5;
}

template<typename T>
void eadvance_imp(T& p, int n,
              input_iterator_tag){
    std::cout << "input iterator" << std::endl;
    while(n--) ++p;
}

template<typename T>
void eadvance(T& p, int n){
    // T::iterator_category => 
    // 어떤 방법으로 이동시킬 것인가?
    // 반복자의 종류에 따라서 다른 함수를 선택
    eadvance_imp(p, n, 
                typename T::iterator_category());
}

int main(){
    list<int> s = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    auto lp = begin(s);
    auto vp = begin(v);

    // 반복자 p를 5칸 전진하고 싶다.
    // p = p + 5;
    // advance(p, 5); // STL
    // eadvance(p, 5);
    eadvance(lp, 5);
    eadvance(vp, 5);

    cout << *lp << endl;
    cout << *vp << endl;
}