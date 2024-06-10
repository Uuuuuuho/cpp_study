#include "02_doubly_linked_list.h"

int main()
{
    doublyLinkedList<int> dll;
    dll.initializeList();
    dll.insert(15);
    dll.insert(16);
    dll.insert(11);
    dll.insert(30);
    dll.print();
    dll.deleteNode(17);
    dll.deleteNode(16);
    dll.print();
    return 0;
}

