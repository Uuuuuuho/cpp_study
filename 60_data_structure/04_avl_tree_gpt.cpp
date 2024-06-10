#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    int height;
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = NULL;
    }

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node* newNode(int data) {
        Node* node = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return node;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, int data) {
        if (node == NULL) {
            return newNode(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        }
        else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        else {
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data) {
            return rightRotate(node);
        }

        if (balance < -1 && data > node->right->data) {
            return leftRotate(node);
        }

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    /* Delete method implementation */
    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current->left != NULL) {
            current = current->left;
        }

        return current;
    }

    Node* deleteNode(Node* node, int data) {
        if (node == NULL) {
            return node;
        }

        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        }
        else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        }
        else {
            if ((node->left == NULL) || (node->right == NULL)) {
                Node* temp = node->left ? node->left : node->right;

                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                }
                else {
                    *node = *temp;
                }

                delete temp;
            }
            else {
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == NULL) {
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

};

int main() {
    AVLTree tree;

    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);


    tree.root = tree.deleteNode(tree.root, 25);

    cout << "Preorder traversal of the constructed AVL tree is:\n";
    tree.preOrder(tree.root);
    return 0;
}
