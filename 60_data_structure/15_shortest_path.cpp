// <Shortest Path>
#if 0
#include <iostream>
using namespace std;
#define LARGE 2000
struct MatrixWdigraph {
	void ShortestPaht(const int, const int);
	void PrintPath(int, int);
	int length[5][5];
	int dist[5];
	int daddy[5];
	int Choose(int);
};
void MatrixWdigraph::ShortestPaht(const int n, const int v) {
	//dist[j], 0 <= j < n은 n개의 정점을 가진 방향 그래프 G에서 정점 v에서 정점j까지의
	//최단 경로  길이로 설정됨. 간선의 길이는 length[i][j]로 주어짐
	//path 출력 위해 각 노드i의 직전도시를 일단 v라고 daddy[i]에 저장하자
	int s[5];
	int i;
	for (i = 0; i < n; i++) {
		s[i] = false;
		dist[i] = length[v][i];
		daddy[i] = v;
	}
	s[v] = true;
	dist[v] = 0;
	int u = Choose(v);//Choose returns a value u such that: dist[u] = minimum dist[w], where s[w] = false
	for(i = 0; i< n-2; i++){//정점 v로부터 n-1개 경로를 결정
		s[u] = true;
		for (int w = 0; w < n; w++)
			if (!s[w] && dist[u] + length[u][w] < dist[w]) {//w가 출발점이 아니고, 직접거리보다 우회로가 짧으면 
				dist[w] = dist[u] + length[u][w];//path 출력 위해 수정
				daddy[w] = u;//w의 아빠를 u로 변경
				u = w;
			}
	}
}
int MatrixWdigraph::Choose(int v) {
	int u;
	for (int i = 0; i < 4; i++) 
		if (dist[i] < dist[i+1]) u=i;
	return u;
}
void MatrixWdigraph::PrintPath(int v, int d) {//daddy 이용한 버전
	//print path from source v to destination d
	if (d == v) cout << v << " ";
	else {
		PrintPath(v, daddy[d]);
		cout << d << " ";
	}
}
int main() {
	MatrixWdigraph matrix;
	matrix.length[0][0] = LARGE;
	matrix.length[0][1] = 50;
	matrix.length[0][2] = 45;
	matrix.length[0][3] = 10;
	matrix.length[0][4] = LARGE;
	matrix.length[1][0] = LARGE;
	matrix.length[1][1] = LARGE;
	matrix.length[1][2] = 10;
	matrix.length[1][3] = 15;
	matrix.length[1][4] = LARGE;
	matrix.length[2][0] = LARGE;
	matrix.length[2][1] = LARGE;
	matrix.length[2][2] = LARGE;
	matrix.length[2][3] = LARGE;
	matrix.length[2][4] = 30;
	matrix.length[3][0] = 20;
	matrix.length[3][1] = LARGE;
	matrix.length[3][2] = LARGE;
	matrix.length[3][3] = LARGE;
	matrix.length[3][4] = 15;
	matrix.length[4][0] = LARGE;
	matrix.length[4][1] = 20;
	matrix.length[4][2] = 35;
	matrix.length[4][3] = LARGE;
	matrix.length[4][4] = LARGE;
	matrix.ShortestPaht(5, 0);
	matrix.PrintPath(0, 1);
}
#endif
#if 1
#include <iostream>
#include <algorithm>
using namespace std;
#define LARGE 2000
struct MatrixWdigraph {
	void ShortestPaht(const int, const int);
	void PrintPath(int, int);
	void AllLengths(const int);
	void PrintMiddlePath(int, int);
	int length[7][7];
	int Choose(int);
	int via[7][7];
};
void MatrixWdigraph::AllLengths(const int n) {
	//length[n][n]은 n개의 정점을 가진 그래프의 인접행렬이다.
	//a[i][j]는 i와 j 사이의 최단 경로의 길이이다.
	int a[7][7] = { NULL };
	for (int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			via[i][j] = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = length[i][j];//length를 a에 복사
	for(int k = 0;k<n;k++)
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
				if((a[i][k]+a[k][j])<a[i][j]){//k를 거치면 더 좋아지는지 확인
					a[i][j] = a[i][k] + a[k][j];
					via[i][j] = k;//via[i][j] = -1로 초기화 가정
				}
}
void MatrixWdigraph::PrintMiddlePath(int i, int j) {//private workhorse
	//print path between source i to destination j excluding i and j
	int k = via[i][j];
	if (k >= 0) {//거쳐야할 중간노드 k really exists!
		PrintMiddlePath(i, k);
		cout << k << " ";
		PrintMiddlePath(k, j);
	}
}
void MatrixWdigraph::PrintPath(int i, int j) {//public funtion
	//print path from source i to destination j
	cout << i << " ";//print the first node
	if (i == j)return;//no more to print, so return;
	PrintMiddlePath(i, j);//print middle path
	cout << j << " " << endl;
}
int main() {
	MatrixWdigraph matrix;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			matrix.length[i][j] = LARGE;
	matrix.length[0][1] = 6;
	matrix.length[0][2] = 5;
	matrix.length[0][3] = 5;
	matrix.length[1][4] = -1;
	matrix.length[2][1] = -2;
	matrix.length[2][4] = 1;
	matrix.length[3][2] = -2;
	matrix.length[3][5] = -1;
	matrix.length[4][6] = 3;
	matrix.length[5][6] = 3;
	matrix.AllLengths(7);
	matrix.PrintPath(0, 6);
}
#endif