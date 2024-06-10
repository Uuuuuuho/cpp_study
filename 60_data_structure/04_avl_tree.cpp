#include "04_avl_tree.h"
#include <iostream>

template <class elemType>
void insertTest(AVLNode<elemType> *&root,
                  AVLNode<elemType> *newNode, bool &isTaller)
{}
int main()
{
  AVLNode<int> *root = new AVLNode<int>(50);
  AVLNode<int> *tmp = new AVLNode<int>(40);
  bool tmp_bool = false;
  insertIntoAVL(root, tmp, tmp_bool);
  inorderTraversal(root);
  std::cout << std::endl;

  tmp_bool = false;
  tmp = new AVLNode<int>(70);
  insertIntoAVL(root, tmp, tmp_bool);
  inorderTraversal(root);
  std::cout << std::endl;

  tmp_bool = false;
  tmp = new AVLNode<int>(80);
  insertIntoAVL(root, tmp, tmp_bool);
  inorderTraversal(root);
  std::cout << std::endl;

  tmp_bool = false;
  tmp = new AVLNode<int>(75);
  insertIntoAVL(root, tmp, tmp_bool);
  inorderTraversal(root);
  std::cout << std::endl;

  std::cout << "test done!" << std::endl;
}