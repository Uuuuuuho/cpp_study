#include "28_rbtree1.h"

// Main function.
int main() {
  // Insert some nodes into the tree.
  insert(10);
  insert(5);
  insert(15);
  insert(2);
  insert(7);
  insert(12);
  insert(17);

  // Print the tree in sorted order.
  print_tree(root);
  std::cout << "\n";

  // Delete a node from the tree.
  delete_node(10);

  // Print the tree in sorted order.
  print_tree(root);
  std::cout << "\n";

  return 0;
}

// Example input data.
int data[] = {10, 5, 15, 2, 7, 12, 17};
