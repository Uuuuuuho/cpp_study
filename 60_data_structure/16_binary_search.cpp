// <BinarySearch>
#include <iostream>
using namespace std;
int BinarySearch(int *a, const int x, const int n) {
	//정렬된 배열 a[0], ... , a[n-1]에서 x를 탐색한다.
	int left = 0, right = n - 1;
	while (left <= right) {
		//원소가 더 있는 한
		int middle = (left + right) / 2;
		if (x < a[middle]) right = middle - 1;
		else if (x > a[middle]) right = middle + 1;
		else return middle;
	}// while의 끝
	return -1;//발견되지 않음
}
int main() {
	int arr[5] = { 1, 3, 16, 4, 25 };
	cout << BinarySearch(arr, 16, 5) << endl;
}