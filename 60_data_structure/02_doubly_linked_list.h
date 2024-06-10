#include <iostream>
using namespace std;

template <typename T>
struct nodeType
{
    T info;
    nodeType<T> *next;
    nodeType<T> *back;
};

template<typename T>
class doublyLinkedList
{
public:
    const doublyLinkedList<T> &operator=
                    (const doublyLinkedList<T> &);
    void initializeList();
    bool isEmptyList() const;
    void destroy();
    void print() const;
    void reversePrint() const;
    int length() const;
    T front() const;
    T back() const;
    bool search(const T& searchItem) const;
    void insert(const T& insertItem);
    void deleteNode(const T& deleteItem);
    doublyLinkedList();
    doublyLinkedList(const doublyLinkedList<T>& otherList);
    ~doublyLinkedList();
protected:
    int count;
    nodeType<T> *first;
    nodeType<T> *last;
private:
    void copyList(const doublyLinkedList<T>& otherList);
};


template <typename T>
void doublyLinkedList<T>::initializeList()
{
    destroy();
}

template <typename T>
bool doublyLinkedList<T>::isEmptyList() const
{
    return false;
}

template <typename T>
void doublyLinkedList<T>::destroy()
{
    nodeType<T> *temp;
    while(first != nullptr)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

template <typename T>
void doublyLinkedList<T>::print() const
{
    nodeType<T> *current;
    current = first;
    while(current!=nullptr)
    {
        cout << current->info << " ";
        current = current->next;
    }
}

template <typename T>
void doublyLinkedList<T>::reversePrint() const
{
    nodeType<T> *current;
    current = last;
    while(current != nullptr)
    {
        cout << current->info << " ";
        current = current->back;
    }
}

template <typename T>
int doublyLinkedList<T>::length() const
{
    return count;
}

template <typename T>
T doublyLinkedList<T>::front() const
{
    assert(first != nullptr);
    return first->info;
}

template <typename T>
T doublyLinkedList<T>::back() const
{
    assert(last != nullptr);
    return last->info;
}

template <typename T>
bool doublyLinkedList<T>::search(const T &searchItem) const
{
    bool found = false;
    nodeType<T> *current;
    current = first;
    
    while(current != nullptr && !found)
        if(current->info >= searchItem) found = true;
        else current = current->next;
    return found;
}

template <typename T>
void doublyLinkedList<T>::insert(const T &insertItem)
{
    nodeType<T> *current;
    nodeType<T> *trailCurrent;
    nodeType<T> *newNode;
    bool found;

    newNode = new nodeType<T>;
    newNode->info = insertItem;
    newNode->next = nullptr;
    newNode->back = nullptr;

    if(first == nullptr)
    {
        first = newNode;
        last  = newNode;
        count++;
    }
    else
    {
        found = false;
        current = first;

        while(current != nullptr && !found)
            if(current->info >= insertItem) found = true;
            else{
                trailCurrent = current;
                current = current->next;
            }
        if(current==first)
        {
            first->back = newNode;
            newNode->next = first;
            first = newNode;
            count++;
        }
        else{
            if(current != nullptr){
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                last = newNode;
            }
        }
    }
}

template <typename T>
void doublyLinkedList<T>::deleteNode(const T &deleteItem)
{
    nodeType<T> *current;
    nodeType<T> *trailCurrent;
    bool found;

    if(first == nullptr) cout << "cannot delet efrom an empty list" << endl;
    else if(first->info == deleteItem)
    {
        current = first;
        first = first->next;

        if(first != nullptr) first->back = nullptr;
        else              last = nullptr;

        count--;
        delete current;
    }    
    else{
        found = false;
        current = first;
        while(current != nullptr && !found)
            if(current->info >= deleteItem) found = true;
            else                            current = current->next;
        
        if(current == nullptr) cout << "the item to be deleted is not in "
                                 << "the list" << endl;
        else if(current->info == deleteItem)
        {
            trailCurrent = current->back;
            trailCurrent->next = current->next;

            if(current->next != nullptr)
                current->next->back = trailCurrent;
            if(current == last)
                last = trailCurrent;
            
            count--;
            delete current;
        }
        else cout << "the item to be deleted is not in the list." << endl;
    }
}

template <typename T>
doublyLinkedList<T>::doublyLinkedList()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <typename T>
doublyLinkedList<T>::doublyLinkedList(const doublyLinkedList<T> &otherList)
{
}

template <typename T>
doublyLinkedList<T>::~doublyLinkedList()
{
}

