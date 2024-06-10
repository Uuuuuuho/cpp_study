#include <iostream>
using namespace std;

template <class elemType>
struct AVLNode
{
  elemType info;
  int bfactor;
  AVLNode<elemType> *llink;
  AVLNode<elemType> *rlink;
  AVLNode(int);
};
template <class elemType>
inline AVLNode<elemType>::AVLNode(int data)
{
  info = data;
  bfactor = 0;
  llink = nullptr;
  rlink = nullptr;
}
template <class elemType>
void rotateToLeft(AVLNode<elemType>* &root)
{
  AVLNode<elemType> *p;

  if(root == NULL) cerr << "error in the tree" << endl;
  else if(root->rlink == NULL) cerr << "error in the tree:"
                                    << "no right subtree to rotate" << endl;
  else{
    p = root->rlink;
    root->rlink = p->llink;
    p->llink = root;
    root = p;
  }
}
template <class elemType>
void rotateToRight(AVLNode<elemType>* &root)
{
  AVLNode<elemType> *p;

  if(root == NULL) cerr << "error in the tree" << endl;
  else if(root->llink == NULL) cerr << "error in the tree:"
                                    << "no right subtree to rotate" << endl;
  else{
    p = root->llink;
    root->llink = p->rlink;
    p->rlink = root;
    root = p;
  }
}
template <class elemType>
void balanceFromLeft(AVLNode<elemType>* &root)
{
  AVLNode<elemType> *p;
  AVLNode<elemType> *w;

  p = root->llink;

  switch (p->bfactor)
  {
    case -1:
      root->bfactor = 0;
      p->bfactor = 0;
      rotateToRight(root);
      break;
    case 0:
      cerr << "error: cannot balance from the right" << endl;
      break;
    case 1:  
      w = p->rlink;
      switch (w->bfactor)
      {
      case -1:
        root->bfactor = 1;
        p->bfactor = 0;
        break;
      case 0:
        root->bfactor = 0;
        p->bfactor = 0;
      case 1:
        root->bfactor = 0;
        p->bfactor = -1;
      default:
        break;
      }
      break;
    default:
      break;
  }
}
template <class elemType>
void balanceFromRight(AVLNode<elemType>* &root)
{
  AVLNode<elemType> *p;
  AVLNode<elemType> *w;

  p = root->rlink;

  switch (p->bfactor)
  {
    case -1:
      w = p->llink;
      switch (w->bfactor)
      {
      case -1:
        root->bfactor = 0;
        p->bfactor = 1;
        break;
      case 0:
        root->bfactor = 0;
        p->bfactor = 0;
        break;
      case 1:
        root->bfactor = -1;
        p->bfactor = 0;
        break;
      default:
        break;
      }
      break;
    case 0:
      cerr << "error: cannot balance from the left" << endl;
      break;
    case 1:  
      root->bfactor = 0;
      p->bfactor = 0;
      rotateToLeft(root);
      break;
    default:
      break;
  }
}
template <class elemType>
void insertIntoAVL(AVLNode<elemType> *&root,
                  AVLNode<elemType> *newNode, bool &isTaller)
{
  if(root == NULL){
    root = newNode;
    isTaller = true;
  }
  else if(root->info == newNode->info)
    cerr << "no duplicates are allowed" << endl;
  else if(root->info > newNode->info){
    insertIntoAVL(root->llink, newNode, isTaller);

    if(isTaller)
      switch (root->bfactor)
      {
        case -1:
          balanceFromLeft(root);
          isTaller = false;
          break;
        case 0:
          root->bfactor = -1;
          isTaller = true;
          break;
        case 1:
          root->bfactor = 0;
          isTaller = false;
        default:
          break;
      }
    else{
      insertIntoAVL(root->rlink, newNode, isTaller);
      if(isTaller)
        switch (root->bfactor)
        {
          case -1:
            root->bfactor = 0;
            isTaller = false;
            break;
          case 0:
            root->bfactor = 1;
            isTaller = true;
            break;
          case 1:
            balanceFromRight(root);
            isTaller = false;
            break;
          default:
            break;
        }
    }
  }
  else if(root->info < newNode->info){
    insertIntoAVL(root->rlink, newNode, isTaller);

    if(isTaller)
      switch (root->bfactor)
      {
        case -1:
          isTaller = false;
          break;
        case 0:
          root->bfactor = 1;
          isTaller = true;
          break;
        case 1:
          balanceFromRight(root);
          root->bfactor = 0;
          isTaller = false;
        default:
          break;
      }
    else{
      insertIntoAVL(root->llink, newNode, isTaller);
      if(isTaller)
        switch (root->bfactor)
        {
          case -1:
            balanceFromLeft(root);
            root->bfactor = 0;
            isTaller = false;
            break;
          case 0:
            root->bfactor = -1;
            isTaller = true;
            break;
          case 1:
            isTaller = false;
            break;
          default:
            break;
        }
    }
  }
}
template <class elemType>
void inorderTraversal(AVLNode<elemType> *&root)
{
  if(root->llink != NULL) inorderTraversal(root->llink);
  cout << root->info << " ";
  if(root->rlink != NULL) inorderTraversal(root->rlink);
}