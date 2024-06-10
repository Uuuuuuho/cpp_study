#include <fstream>
#include <queue>
#include <algorithm>
#include "mstree.h"

int NNODES; //#nodes in the graph is global
priority_queue<Edge, vector<Edge>, Compare> *PQ;
void sollin(){
  Sets sets(NNODES);
  int nedges = 0; //edges found up to now.
  while(nedges < NNODES -1){
    if(PQ[nedges].empty()) throw "No Spanning Tree Exists.";
    Edge e[NNODES];
    for(int i = 0; i < NNODES && nedges != NNODES -1; i++){
      e[i] = PQ[i].top(); PQ[i].pop();
      if(e[i].v1 != sets.Find(e[i].v2) && //parent가 서로 다르면
      e[i].v2 != sets.Find(e[i].v1)){
        sets.Union(e[i].v2,e[i].v1);//v1을 v2의 부모로 지정
        cout << e[i];
        nedges++;
      }
      else{
        PQ[e[i].v2].pop();
        PQ[e[i].v1].push(PQ[e[i].v2].top());
        PQ[e[i].v2].push(PQ[e[i].v1].top());
      }
    }
  }
}
void ReadEdges4sollin(istream& is){
  PQ = new priority_queue<Edge, vector<Edge>, Compare>[NNODES];
  Edge e;
  while(GetEdge(is, NNODES, e)){
    PQ[e.v1].push(e);
    PQ[e.v2].push(e);
  }
}
int main(int argc, char *argv[]){
  ifstream is;
  if(argc == 1) is.open("mstree.dat");
  else is.open(argv[1]);
  if(!is){ cerr << "No such input file\n"; return 1;}
  is >> NNODES;
  if(NNODES < 2) { cerr << "#nodes must be 2.." << endl; return 1;}
  try{ ReadEdges4sollin(is); sollin();}//모든 Edges를 읽어드려서 kruskal 돌려
  catch(char const *str){
    cerr << "Exception: " << str << endl; return 1;
  }
}

// <sollin result>
// (0,5) : 10
// (1,6) : 14
// (2,3) : 12
// (3,4) : 22
// (4,5) : 25
// (1,2) : 16