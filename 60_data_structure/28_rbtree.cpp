#include <iostream>
#include "28_rbtree.h"

int main() {
    RBTree<int> tree;

    // insert some elements
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(11);
    tree.insert(13);
    tree.insert(16);
    tree.insert(18);

    // print the tree in order
    std::cout << "In-order traversal: ";
    tree.printInOrder();
    std::cout << std::endl;

    // check if some elements are present
    std::cout << "Find 5: " << tree.find(5) << std::endl;
    std::cout << "Find 11: " << tree.find(11) << std::endl;
    std::cout << "Find 20: " << tree.find(20) << std::endl;

    // // remove some elements
    // tree.remove(5);
    // tree.remove(11);
    // tree.remove(15);

    // // print the tree in order again
    // std::cout << "In-order traversal: ";
    // tree.printInOrder();
    // std::cout << std::endl;

    return 0;
}