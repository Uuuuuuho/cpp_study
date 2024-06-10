#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <stack>

enum Color {RED, BLACK};

template<typename T>
class RBTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* parent;
        Color color;
        Node(T data, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr, Color color = RED)
            : data(data), left(left), right(right), parent(parent), color(color) {}
    };

    Node* root;

    // helper functions for insert and delete
    void rotateLeft(Node* x);
    void rotateRight(Node* x);
    void insertFixup(Node* z);
    void transplant(Node* u, Node* v);
    void deleteFixup(Node* x);
    Node* minimum(Node* x);
    Node* maximum(Node* x);

public:
    RBTree() : root(nullptr) {}
    ~RBTree() { clear(); }

    void clear();
    void clear(Node* node);
    bool empty() const { return root == nullptr; }

    void insert(const T& data);
    bool remove(const T& data);

    bool find(const T& data) const;
    void printInOrder() const;
};

template <typename T>
void RBTree<T>::insert(const T& data) {
    Node* parent = nullptr;
    Node* current = root;
    Node* node = new Node(data);

    while (current != nullptr) {
        parent = current;

        if (node->data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    node->parent = parent;

    if (parent == nullptr) {
        root = node;
    } else if (node->data < parent->data) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    insertFixup(node);
}

template<typename T>
void RBTree<T>::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

template<typename T>
void RBTree<T>::rotateRight(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

template<typename T>
void RBTree<T>::insertFixup(Node* z) {
    while (z->parent != nullptr && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

template<typename T>
void RBTree<T>::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

template<typename T>
void RBTree<T>::deleteFixup(Node* x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        }
        else {
            Node* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

template<typename T>
typename RBTree<T>::Node* RBTree<T>::minimum(Node* x) {
    while (x->left != nullptr) {
        x = x->left;
    }
    return x;
}

template<typename T>
typename RBTree<T>::Node* RBTree<T>::maximum(Node* x) {
    while (x->right != nullptr) {
        x = x->right;
    }
    return x;
}

template<typename T>
void RBTree<T>::clear() {
    clear(root);
    root = nullptr;
}

template<typename T>
void RBTree<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<typename T>
bool RBTree<T>::remove(const T& data) {
    Node* z = root;
    while (z != nullptr) {
        if (data == z->data) {
            break;
        } else if (data < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    }
    if (z == nullptr) {
        return false;
    }
    Node* y = z;
    Color y_original_color = y->color;
    Node* x;
    if (z->left == nullptr) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nullptr) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    if (y_original_color == BLACK) {
        deleteFixup(x);
    }
    return true;
}

template<typename T>
bool RBTree<T>::find(const T& data) const {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

template<typename T>
void RBTree<T>::printInOrder() const {
    if (root != nullptr) {
        std::stack<Node*> s;
        Node* current = root;
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            std::cout << current->data << " ";
            current = current->right;
        }
    }
    std::cout << std::endl;
}

#endif