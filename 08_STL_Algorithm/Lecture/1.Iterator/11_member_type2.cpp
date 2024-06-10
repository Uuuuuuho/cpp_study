#include <iterator>

/*  코드 수정
    C++ OOP 원칙에 따라 공통 코드를 base class로 정의함
    Template으로 instance 생성단계에서 dynamic dispatching
*/
template<typename Category,
         typename T,
         typename Distance = std::ptrdiff_t,
         typename Pointer = T*,
         typename Reference = T&>
struct iterator{
    using iterator_category = Category;
    using value_type = T;
    using pointer = Pointer;
    using reference = Reference;
    using difference_type = Distance;
};

template<typename T> struct Node
{
    T data;
    Node* next;

    Node(const T& a, Node* n): data(a), next(n){}
};
template<typename T> class slist_iterator 
    : public iterator<forward_iterator_tag, T>
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