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
  /*  
    open addressing
    |----linear probing		: hash value에 1씩 increment.
    |----double hashing		: 서로 다른 hash function을 doubly 수행.
    |----random probing		: 'random' number를 increment하여 probing을 수행. 이상적으로 적용하지 어려움.
    |----rehashing			: 여러 hash function을 준비하고, collision이 발생하면 다른 hash function을 수행.
    |----quadratic probing	: linear probing과 유사하게 adding number를 quadratic oder로 increment 하는 방식.
    chaining
    |----item insertion and collision	: hash_1(key)==hash_2(key)인 case를 의미함.
    |----search							: probing을 수행하지 않기 때문에 hash value entry에 대해 sequential search를 수행.
    |----deletion						: 입력 key에 대한 element를 찾기 위해 sequential search를 수행.
    |----overflow						: open addressing은 hash table entry가 element보다 많아야하지만 chaning은 더이상 그러한 고민이 불필요함.
  */
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
  if(WhereInHT(name, iter)) (*iter).val = val;//change its value to a new one
  else                      HT[hashfcn(name)].push_front(Node(name,val));
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