#include <iostream>

/* 핵심 개념
    list, vector를 포함한 container에 대해 "find, reverse, remove" 등의 함수를 만들고자 하는 경우.
    1. 템플릿을 사용하지 않고 find, reverse, remove를 멤버함수로 만든다면
        : 3개 컨테이터 * 3개 함수 * 3개 타입 = 27개 함수가 필요
    2. 템플릿을 사용해서 find, reverse,remove를 멤버함수로 만든다면
        : 3개 컨테이너 *3개 함수 = 9개 함수가 필요
    3. find, reverse, remove를 멤버 함수가 아닌 일반 함수를 만든다면
        : 모든컨테이너에 동작하는 3개 함수가 필요
        : 모든 컨테이너의 요소르 ㄹ동일한 방식으로 접근할 수 있어야 한다. => iterator가 필요함.
    4. STL은 자료구조와 알고리즘이 분리된 라이브러리
        : 알고리즘 함수는 자신이 어떤 자료구조에 대해 연산을 수행하는지 모른다.
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