// <InsertionSort>
#include <iostream>
using namespace std;
template<class T>
void Insert(const T&e, T*a, int i) {
	//e를 정렬된 리스트 a[1:i]에 삽입하여(e를 등수에 맞춰서)
	//결과 리스트 a[1:i+1]도 정렬되게 한다.
	//배열 a는 적어도 i+2 원소를 포함할 공간을 갖고 있어야한다.
	while (a[i] == NULL) {
		i--;
	}
	while (e < a[i]) {
		a[i+1] = a[i];
		i--;
	}
	a[++i] = e;
}
template<class T>
void InsertionSort(T*a, const int n) {
	//a[1:n]을 비감소 순으로 정렬한다.
	for (int j = 2; j <= n; j++) {
		T temp = a[j];
		Insert(temp, a, j - 1);
	}
}
int main() {
	int a[6] = { 0, 10, 15, 20, 25 };
	Insert(18, a, 5);
	for (int i = 0; i < 6; i++)
		cout << a[i] << " ";
	cout << endl;
	int b[6] = { 2,3,4,5,1 };
	InsertionSort(b, 5);
	for (int i = 0; i < 6; i++)
		cout << b[i] << " ";
	cout << endl;
}