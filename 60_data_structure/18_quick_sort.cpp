// <QuickSort>
#include <iostream>
using namespace std;
template <class T>
void QuickSort(T *a, const int left, const int right) {
	//a[left:right]를 비감소 순으로 정렬한다.
	//a[left]는 피벗으로 임의로 선정한다. 변수 i와 j는
	//서브리스트를 분할하는데 사용되어 항상 a[m] < pivot, m<i와
	//a[m] >= pivot, m>j를 만족시킨다. a[left] <= a[right+1]이라고 가정한다.
	if (left < right) {
		int i = left;
		int j = right + 1;
		int pivot = a[left];
		do {//계속하시오
			do i++; while (a[i] < pivot);
			do j--; while (a[j] > pivot);
			if (i < j) swap(a[i], a[j]);//이상한 놈들을 맞교환
		} while (i < j);//i<j이면
		swap(a[left], a[j]);//피봇을 알맞은 위치로 보냄
		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
}
int main() {
	int R[10] = { 26, 5, 37, 1, 61, 11, 59, 15, 48, 19 };
	QuickSort(R, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << R[i] << " ";
	cout << endl;
}