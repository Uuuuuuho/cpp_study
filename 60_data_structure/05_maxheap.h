#include <iostream>
using namespace std;

template <class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize);

template <class T>
class MaxHeap{
public:
        MaxHeap();
        MaxHeap(int);//constructor
        void Push(const T&e);
        void Pop();
        bool IsEmpty(){return heapSize == 0;}
        T Top(){
                return heap[1];
        }
private:
        int heapSize; // # of elements in heap
        int capacity; // size of the array heap
        T *heap; // element array
template <class T2>
friend ostream& operator<<(ostream&, MaxHeap<T2>&);
};
template <class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize){
        T tmp[newSize];
        for(int i = 0;i < oldSize;i++)
                tmp[i] = a[i];
        a[newSize];
        for(int i = 0;i < newSize;i++)
                a[i] = tmp[i];
}
template <class T>
ostream& operator<<(ostream& os, MaxHeap<T>& H){
        os << "<Heap Contents> ";
        for (int i = 1; i <=H.heapSize; i++)
                os << i << ":" << H.heap[i] << " ";
        os << endl;
}

template <class T>
MaxHeap<T>::MaxHeap()
{
        capacity = 0;
        heap = new T[capacity+1]; // heap[0]는 사용안함, constructor
}

template <class T>
MaxHeap<T>::MaxHeap(int theCapacity) : heapSize(0)
{
        if (theCapacity < 1) throw "Must be +ve";
        capacity = theCapacity;
        heap = new T[capacity+1]; // heap[0]는 사용안함, constructor
}
template <class T>
void MaxHeap<T>::Push(const T& e){
        if(heapSize == capacity){
                ChangeSize1D(heap, capacity + 1, 2*capacity +1);
                capacity *= 2;
        }
        int currentNode = ++heapSize;//미리 자리 확보
        while(currentNode != 1 && heap[currentNode/2]<e){//부모 노드로 이동
                heap[currentNode] = heap[currentNode/2];
                currentNode /= 2;
        }
        heap[currentNode] = e;
}
template <class T>
void MaxHeap<T>::Pop(){
        if(IsEmpty()) throw "Heap is empty. Cannot delete";
        heap[1].~T();//최대 원소 삭제
        //히프의 마지막 원소 제거
        T lastE = heap[heapSize--];
        //tricle down
        int currentNode = 1; //루트
        int child = 2;
        while(child<=heapSize)//왼쪽 아들이 트리에 존대한다면
        {//child를 currentNode의 큰 자식으로 설정
                if(child < heapSize && heap[child] < heap[child+1])child++;
                //currentNode에 last E를 삽입할 수 있는가?
                if(lastE>=heap[child]) break;//yes
                //no
                heap[currentNode] = heap[child]; //자식으로 이동
                currentNode = child; child*=2;//한 레벨 내려감
        }
        heap[currentNode] = lastE;
}