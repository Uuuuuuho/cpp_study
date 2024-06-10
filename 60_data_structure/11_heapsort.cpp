#include <iostream>
using namespace std;

template<class T>
void PrintArray(T *a, const int n){
  for(int i = 1; i <= n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

template<class T>
void Adjust(T *a, const int root, const int n){//root를 기준으로 heap을 만족하도록 하는 함수
  T e = a[root];//a[1]

  int j;
  for(j = 2*root; j <= n; j *=2){
    if(j < n && a[j] < a[j+1]) j++;//동생이 나보다 크면 동생한테 순서를 넘겨준다
    if(e >= a[j]) break;//할아버지가 나보다 크면
    a[j/2] = a[j];//아들이 아버지보다 크면 아들을 아버지 자리로
  }
  a[j/2] = e;//아들자리에 아버지 옮겨드리기 j/2 마지막에 j를 2배하기 때문
}

template<class T>
void HeapSort(T *a, const int n){
  for(int i = n/2; i >= 1; i--)//heapify
          Adjust(a, i, n);
  for(int i = n-1; i >= 1; i--){
    swap(a[1], a[i+1]); //제일 큰값 맨뒤로
    Adjust(a, 1, i);    //제일 큰값 빼고 heap 정렬
    PrintArray(a, i);   //1등 빼고 print
  }
}

int main(){
  int a[] = {0, 26, 5, 77, 1, 61, 11, 59, 15, 48, 19};

  int n = sizeof(a)/sizeof(int) - 1;
  cout << "Before Sorting : "; PrintArray(a, n);
  HeapSort(a, n);
  cout << "After Sorting : "; PrintArray(a, n);
}

// <heapsort result>
// Before Sorting : 26 5 77 1 61 11 59 15 48 19
// 61 48 59 15 19 11 26 5 1
// 59 48 26 15 19 11 1 5
// 48 19 26 15 5 11 1
// 26 19 11 15 5 1
// 19 15 11 1 5
// 15 5 11 1
// 11 5 1
// 5 1
// 1
// After Sorting : 1 5 11 15 19 26 48 59 61 77