#include <iostream>
/* 핵심 개념
    1. 반복자 타입 이름
        : 각 컨테이너의 반복자 이름을 "iterator"라는 약속된 이름으로 typedef (또는 using)으로 제공한다.
        : 반복자의 타입 이름은 "컨테이너이름::iterator"로 접근
    2. 반복자 덕분에 efind는 배열뿐만 아니라 모든 선형 자료구조에서 "선형 검색"을 수행할 수 있다.
 */
/* 
    1. p가 raw pointer라면 ++, * 연산시 동작 방식을 변경할 수 없음
    2. p가 user define type의 객체라면
        - ++p: operator++() 함수가 호출됨
        - *p: operator*() 함수가 호출됨
    3. 반복자 (iterator)
        - 포인터와 유사하게 동작하는 객체. 연속된 메모리가 아닌 자료구조(컨테이너)의 요소를 열거할 때 배열과 동일한 방식으로 사용 가능해 진다.
 */
template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 val){
    while (first != last && *first != val) ++first;
    return first;
}

template<typename T> struct Node
{
    T data;
    Node* next;

    Node(const T& a, Node* n): data(a), next(n){}
};

/* 
    1. 내부적으로 slits안의 Node를 가리키는 멤버가 있어야함
        : Node<T>* current 멤버 이터
    2. efind로 전달하려면 3가지 연산자가 재정의되어야함
        : ++, *, !=
        : ==도 제공
 */
template<typename T> class slist_iterator
{
    Node<T>* current = nullptr;
public:
    slist_iterator(Node<T>* p = nullptr) : current(p) {}
    slist_iterator& operator++(){
        current = current->next;
        return *this;
    }
    T& operator*(){ return current->data; }
    bool operator==(const slist_iterator& it){
        return current == it.current;
    }
    bool operator!=(const slist_iterator& it){
        return current != it.current;
    }
};

template<typename T> class slist
{
    Node<T>* head = 0;
public:
    void push_front(const T& a){
        head = new Node<T>(a, head);
    }

    /* 반복자 이름을 약속된 형태 "iterator"
        typedef slit_iterator<T> iterator;
     */

    using iterator = slist_iterator<T>;

    iterator begin(){
        return iterator(head);
    }
    iterator end(){
        return iterator(0);
    }
};

int main(){
    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    // slist_iterator<int> p = s.begin();
    slist<int>::iterator p = s.begin();
    slist<int>::iterator p2 = efind(s.begin(), s.end(), 20);

    if(p2 == s.end()) std::cout << "fail" << std::endl;
    else std::cout << *p2 << std::endl;
    // std::cout << *p << std::endl;
    // ++p;
    // std::cout << *p << std::endl;

    // while(p != s.end()){
    //     std::cout << *p << std::endl;
    //     ++p;
    // }

    return 0;
}