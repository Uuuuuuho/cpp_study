#include <iterator>

/* 핵심 개념
    1. 반복자를 만들때 반드시 member type을 제공해야한다.
        member type         T
        difference_type     Signed integer type
        reference           value_type&
        pointer             value_type*
        iteragor_category   컨테이너마다 다른 정의
*/

template<typename T> struct Node
{
    T data;
    Node* next;

    Node(const T& a, Node* n): data(a), next(n){}
};
template<typename T> class slist_iterator
{
    Node<T>* current = nullptr;
public:
    using iterator_category = forward_iterator_tag;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = std::ptrdiff_t;

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