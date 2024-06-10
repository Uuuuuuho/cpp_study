// <hashtest.cpp>
using namespace std;
#include <iostream>
#include <list>
#include <cstring>

//==== this practice is for rehashing. ====

#define INITHTSIZE 3
int HTSIZE = 3; // prime # used
int num_items = 0;
struct Node{
  Node(char* n, float v): name(n),  val(v){}
  char *name;
  float val;
};
list<Node> *HT; // Hash Table Pointer

int hashfcn(char *name){
  // linear probing
  return name[0] * name[strlen(name)-1] % HTSIZE;
}
void rehashing(){
  list<Node> *REF_HT = new list<Node>[HTSIZE<<1];
  list<Node> *tmp_ptr = nullptr;
  // copy the original hash table.
  for(int idx = 0; idx < HTSIZE; idx++){
    for(auto item: HT[idx]){
      REF_HT[idx].push_back(item);
    }
  }
  HTSIZE = HTSIZE << 1;
  tmp_ptr = HT;
  HT = REF_HT;
  delete []tmp_ptr;
}
bool WhereInHT(char *name, list<Node>::iterator& iter){
  int hashval = hashfcn(name);
  for(iter = HT[hashval].begin(); iter!=HT[hashval].end(); iter++)
    if(!strcmp((*iter).name, name)) // iter points to the place
      return true;
  return false;
}
bool GetFromHT(char* name, float& val){
  list<Node>::iterator iter;
  if(WhereInHT(name, iter)){
    val = (*iter).val; // Found the value
    return true;
  }
  return false;
}
void StoreIntoHT(char* name, float val){
  //Hash Table에 name을 키로 val을 값으로 하는 노드를 저장하라
  list<Node>::iterator iter;
  if(WhereInHT(name, iter)) (*iter).val = val;//change its value to a new one
  else {
    HT[hashfcn(name)].push_front(Node(name,val));
    if(++num_items>(HTSIZE>>1)){
      rehashing();
    }
  }
} 
void PrintValue(char* name){
  float val;
  if(!GetFromHT(name, val)) cout << name << " does not exist" << endl;
  else                      cout << name << " " << val << endl;
}

int main(){
  HT = new list<Node>[INITHTSIZE];
  StoreIntoHT((char*)"abro", 23);
  StoreIntoHT((char*)"bb", 34.5);
  StoreIntoHT((char*)"haha", 99);
  StoreIntoHT((char*)"bb", 1234.5);
  PrintValue((char*)"bb");
  PrintValue((char*)"haha");
  PrintValue((char*)"hoho");
}

// <hashtest result>
// bb 1234.5
// haha 99
// hoho does not exist