#include <fstream>
#include <queue>
#include "mstree.h"
int NNODES; // #nodes in the graph is global
priority_queue<Edge, vector<Edge>, Compare> PQ;//짜야되나??
queue<Edge> *Q; // each vertex has a queue
void MoveIntoPQ_EdgesOfNode(int v){
//Move all edges of vertex 'v' into PQ
  while(!Q[v].empty()){
    PQ.push(Q[v].front());
    Q[v].pop();
  }
}
void prim(){
  Sets sets(NNODES);
  int nedges = 0; //#edges found up to now
  while(nedges < NNODES - 1){
    if(PQ.empty()) throw "No Spanning Tree Exists.";
    Edge e = PQ.top(); PQ.pop();
    int root0 = sets.Find(0); //현재 선택된 노드들의 루트를 구한다. 0부터 시작
    if(root0 != sets.Find(e.v1) || root0 != sets.Find(e.v2)){
      sets.Union(e.v1, e.v2);
      cout << e;
      while(!PQ.empty()) PQ.pop();
      MoveIntoPQ_EdgesOfNode(e.v1);
      MoveIntoPQ_EdgesOfNode(e.v2);
      nedges++;
    }
    //꺼낸 e가 자격이 있으면 출력하고 e의 새로운 vertex에 대해 처리한다.
  }
}
void ReadEdges4prim(istream& is){
  Q = new queue<Edge> [NNODES];
  Edge e;
  while(GetEdge(is, NNODES, e)){
    Q[e.v1].push(e);
    Q[e.v2].push(e);
    //Q[e.v1]에 e를 넣고 Q[e.v2]에도 e를 넣는다.
  }
  MoveIntoPQ_EdgesOfNode(0);//0의 edge들을 PQ로 이동한다.
}

int main(int argc, char *argv[]){
  ifstream is;
  if(argc == 1) is.open("mstree.dat");
  else is.open(argv[1]);
  if(!is){ cerr << "No such input file\n"; return 1;}
  is >> NNODES;
  if(NNODES < 2) { cerr << "#nodes must be 2.." << endl; return 1;}
  try{ ReadEdges4prim(is); prim();}//모든 Edges를 읽어드려서 kruskal 돌려
  catch(char const *str){
    cerr << "Exception: " << str << endl; return 1;
  }
}

// <prim result>
// (0,5) : 10
// (4,5) : 25
// (3,4) : 22
// (2,3) : 12
// (1,2) : 16
// (1,6) : 14