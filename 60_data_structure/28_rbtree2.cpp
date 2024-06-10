#include "28_rbtree2.h"

// Test the RBTree implementation
int main() {
    RBTree<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);

    tree.printInOrder(); // Output: 10 20 30 40 50 60 70
    std::cout << std::endl;

    tree.remove(30);
    // tree.remove(50);

    // tree.printInOrder(); // Output: 10 20 40 60 70
    // std::cout << std::endl;

    // std::cout << "Search for value 40: " << (tree.find(40) ? "Found" : "Not found") << std::endl; // Output: Found
    // std::cout << "Search for value 50: " << (tree.find(50) ? "Found" : "Not found") << std::endl; // Output: Not found

    // tree.clear();

    return 0;
}
               
