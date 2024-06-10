#include <iostream>

using namespace std;

enum COLOR{
  RED,
  BLACK
};

// A node in a red-black tree.
struct Node {
  int key;
  bool color;
  Node *left;
  Node *right;
  Node *parent;
};

Node *root = nullptr; /* The root of the red-black tree. */

void init();                    /* Initialize the red-black tree. */
void insert(int key);           /* Insert a new node into the red-black tree. */
void insert_node(Node *new_node, Node *node);   /* Insert a new node into the tree recursively. */
void right_rotate(Node *node);  /* Rotate the tree right around a given node. */
void left_rotate(Node *node);   /* Rotate the tree left around a given node. */
void fix_insert(Node *node);    /* Fix the red-black tree properties after an insertion. */
void delete_node(int key);      /* Delete a node from the red-black tree. */
void print_tree(Node* node);    /* Print the red-black tree in sorted order. */

// Initialize the red-black tree.
void init() {
  root = nullptr;
}

// Insert a new node into the tree recursively.
void insert_node(Node *new_node, Node *node) {
  // If the tree is empty, make the new node the root.
  if (node == nullptr) {
    root = new_node;
    return;
  }

  // If the key is less than the current node, insert the new node into the left subtree.
  if (new_node->key < node->key) {
    insert_node(new_node, node->left);
  } 
  else {
    // Otherwise, insert the new node into the right subtree.
    insert_node(new_node, node->right);
  }
}

// Rotate the tree right around a given node.
void right_rotate(Node *node) {
  // Save the node's left child.
  Node *left_child = node->left;

  // Make the node's left child the new parent.
  node->left = left_child->right;
  if (node->left != nullptr) {
    node->left->parent = node;
  }

  // Make the node the new left child of its parent.
  left_child->parent = node->parent;
  if (node->parent != nullptr) {
    if (node == node->parent->left) {
      node->parent->left = left_child;
    } else {
      node->parent->right = left_child;
    }
  } else {
    root = left_child;
  }

  // Make the node the new right child of its left child.
  left_child->right = node;
  node->parent = left_child;
}

// Rotate the tree left around a given node.
void left_rotate(Node *node) {
  // Save the node's right child.
  Node *right_child = node->right;

  // Make the node's right child the new parent.
  node->right = right_child->left;
  if (node->right != nullptr) {
    node->right->parent = node;
  }

  // Make the node the new right child of its parent.
  right_child->parent = node->parent;
  if (node->parent != nullptr) {
    if (node == node->parent->left) {
      node->parent->left = right_child;
    } else {
      node->parent->right = right_child;
    }
  } else {
    root = right_child;
  }

  // Make the node the new left child of its right child.
  right_child->left = node;
  node->parent = right_child;
}

// Fix the red-black tree properties after an insertion.
void fix_insert(Node *node) {
  // If the new node is the root, there is nothing to do.
  if (node == root) {
    return;
  }

  // If the new node's parent is red, rotate the tree.
  if (node->parent->color == RED) {
    // If the new node is the left child of its parent, perform a right rotation.
    if (node == node->parent->left) {
      right_rotate(node->parent);
    } else {
      // Otherwise, perform a left rotation.
      left_rotate(node->parent);
    }
  }

  // Fix the red-black tree properties recursively.
  fix_insert(node->parent);
}

// Insert a new node into the red-black tree.
void insert(int key) {
  // Create a new node.
  Node *new_node = new Node();
  new_node->key = key;
  new_node->color = RED;
  new_node->left = nullptr;
  new_node->right = nullptr;

  // Insert the new node into the tree.
  insert_node(new_node, root);

  // Fix the red-black tree properties.
  fix_insert(new_node);
}

// Find a node in the red-black tree.
Node *find_node(int key) {
  // Start at the root of the tree.
  Node *node = root;

  // While the node is not null and the key is not equal to the node's key,
  // recursively search the left or right subtree.
  while (node != nullptr && node->key != key) {
    if (key < node->key) {
      node = node->left;
    } else {
      node = node->right;
    }
  }

  // Return the node if it is found, or nullptr if it is not found.
  return node;
}

// Delete a node from the red-black tree.
void delete_node(int key) {
  // Find the node to be deleted.
  Node *node = find_node(key);
  if (node == nullptr) {
    return;
  }

  // If the node has no children, simply remove it.
  if (node->left == nullptr && node->right == nullptr) {
    if (node == root) {
      root = nullptr;
    } else if (node == node->parent->left) {
      node->parent->left = nullptr;
    } else {
      node->parent->right = nullptr;
    }
    delete node;
    return;
  }

  // If the node has only one child, replace it with its child.
  if (node->left == nullptr) {
    node->right->parent = node->parent;
    if (node == root) {
      root = node->right;
    } else if (node == node->parent->left) {
      node->parent->left = node->right;
    } else {
      node->parent->right = node->right;
    }
    delete node;
    return;
  } else if (node->right == nullptr) {
    node->left->parent = node->parent;
    if (node == root) {
      root = node->left;
    } else if (node == node->parent->left) {
      node->parent->left = node->left;
    } else {
      node->parent->right = node->left;
    }
    delete node;
    return;
  }

  // If the node has two children, find the successor and swap the node with the successor.
  Node *successor = node->right;
  while (successor->left != nullptr) {
    successor = successor->left;
  }
  swap(node, successor);

  // Delete the node as if it had only one child.
  delete_node(key);
}


// Print the red-black tree in sorted order.
void print_tree(Node* node) {
  if (node == nullptr) {
    return;
  }

  // Recursively print the left subtree.
  print_tree(node->left);

  // Print the node's key.
  std::cout << root->key << " ";

  // Recursively print the right subtree.
  print_tree(node->right);
}
