#include <unordered_set>

// C style code - typedef 
// typedef int DWORD;
// typedef void(*F)(); 

// C++11 using : code below is same as above
// 장점 1. easier and more convinient thant above.
//     2. available for template and type.
using DWORD = int;
using F = void(*)();

int main()
{
	DWORD n; // int n
	F     f; // void(*f)()
}