#include <iostream>

int main()
{
	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 5,6,7,8 };
	int arr3[4] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
	}

	for (auto e : arr3)
		std::cout << e << std::endl;
}