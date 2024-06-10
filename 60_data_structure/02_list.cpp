#include <iostream>
#include "02_list.h"

ostream& operator<<(ostream& os, IntList& i1){
  Node *ptr = i1.first;
  while(ptr != 0) {
    os << ptr->data << " "; 
    ptr = ptr->link;
  }
  os << endl;
  return os;
}
void IntList::Push_Back(int e){
  if(!first) first = last = new Node(e);
  else{
    last->link = new Node(e);
    last = last->link;
  }
}
int IntList::Front(){
  return first->data;
}
void IntList::Pop_Front(){
  if(!first);
  first = first->link;
}
void IntList::Push_Front(int e){
  if(!first) first = last = new Node(e);
  else{//지우고 넣기가 아니라 내버려 둔 상태에서 넣기
    first = new Node(e, first);
  }
}
void IntList::Insert(int e){
  if(!first) first = last = new Node(e);
  else if(first->data > e) Push_Front(e);
  else if(first->data < e){
    Node *q = first; Node*p = first->link;
    while(p && p->data < e){
      if(p->data == e) break;
      else if(p->data > e){
        q = new Node(e,q->link);
      }
      q = q->link; p = p->link;
    }
    if(!p) Push_Back(e);
  }
}

int main(){
  IntList i1;
  i1.Push_Back(5); i1.Push_Back(7); i1.Push_Back(9);
  cout << i1;
  i1.Push_Front(4); i1.Push_Front(3);
  cout << i1;
  i1.Insert(6); i1.Insert(10); i1.Insert(2);
  i1.Insert(5); i1.Insert(2); i1.Insert(10);
  while(!i1.IsEmpty()){ 
    cout << i1.Front() << " "; 
    i1.Pop_Front();
  }
  cout << endl;
}

// <결과>
// 5 7 9
// 3 4 5 7 9
// 2 3 4 5 7 9 10