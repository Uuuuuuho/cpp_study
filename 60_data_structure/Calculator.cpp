#include <iostream>
#include "Calculator.h"
#include "Adder.h"
using namespace std;
void Calculator::Run()
{
	cout << "두 개의 수를 입력하시오 : ";
	int a, b;
	cin >> a >> b;
	Adder adder(a, b);
	cout << adder.Process() << endl;
}