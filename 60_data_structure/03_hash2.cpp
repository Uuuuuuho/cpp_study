// <hashtest.cpp>
using namespace std;
#define HTSIZE 137 // prime # used
#include <iostream>
#include <list>
#include <cstring>
struct Node{
  Node(char* n, float v): name(n),  val(v){}
  char *name;
  float val;
};
list<Node> HT[HTSIZE]; // Hash Table
int hashfcn(char *name){
  // this is linear probing
  return name[0] * name[strlen(name)-1] % HTSIZE;
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
  int pCount = 0, inc = 1;
  
  if(WhereInHT(name, iter)) (*iter).val = val;
  // value not found
  else{
    int hashIdx = hashfcn(name);

    // if HT entry is not empty
    // Quadratic hashing
    while(!HT[hashIdx].empty()
          && WhereInHT(name,iter)
          && pCount < HTSIZE/2)
    {
      pCount++;
      hashIdx = (hashIdx + inc) % HTSIZE;
      inc = inc + 2;
    }
    // if HT entry is empty
    if(HT[hashIdx].empty()) HT[hashfcn(name)].push_front(Node(name,val));
  }
} 
void PrintValue(char* name){
  float val;
  if(!GetFromHT(name, val)) cout << name << " does not exist" << endl;
  else                      cout << name << " " << val << endl;
}

int main(){
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