
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void readNumber(short &number1 , short &number2)
{
	
	cout << "please Enter numbrer 1 " << endl;
	cin >> number1;
	cout << "please enter number 2 " << endl;
	cin >> number2;
}
void SwapNumber(short &a , short &b)
{
	short Temp = 0;
	Temp = a;
	a = b;
	b = Temp;
}
void printSwapNumber(short &a ,short &b)
{
	cout << "number 1 = " << a << endl;
	cout << "number 2 = " << b << endl;
}
int main()
{
	short number1 = 0;
	short number2 = 0;

	readNumber(number1, number2);
	SwapNumber(number1,number2);
	printSwapNumber(number1, number2);
	
}

