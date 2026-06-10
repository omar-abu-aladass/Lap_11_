/* Documentaion : program read from user number of shape and calclate area */
#include<cmath>
#include<string>
#include <iostream>
using namespace std;
//function read Number from user *****
short readNumber()
{
	short number = 0;

	cout << "choose a shape enter number (1-square , 2-Rectangle , 3-Circle)" << endl;
	cin >> number;
	if (number < 0)
	{
		cout << "Invalid input Dimension must be positive " << endl;
	}
	else if (number > 3)
	{
		cout << "Invalid shape choice !" << endl;
	}

	return number;
}
//function used to calculate area from aquare ****
float CalculateSquare()
{
	float side = 0;

	cout << "please enter side of square " << endl;
	cin >> side;

	float Area = side * side;

	cout << "Area of square :  " << Area << endl;;

	return Area;
}
//function used to calculate area from Regtangle ****
float CalculateRectangle()
{
	float lenght = 0;
	float width = 0;
	float Area = 0;

	cout << "please enter lenght of Regtangle " << endl;
	cin >> lenght;
	cout << "please enter width of Regtangle " << endl;
	cin >> width;
	Area = lenght * width;
	cout << " Area of Regtangle : " << Area << endl;

	return Area;
}
//function used to calculate area from cycle ****
float CalculateCycle()
{
	const double PI = 3.14;
	float radius = 0;
	float Area = 0;

	cout << "please enter radius of cycle " << endl;
	cin >> radius;
	Area = PI * radius * radius;
	cout << "Area of cycle : " << Area << endl;

	return Area;
}
//Select from bath number enter your user , choose and call calculate function ******** 
short Shapes(short number)
{

	switch (number)
	{
	case 1:
		return CalculateSquare();
		break;
	case 2:
		return CalculateRectangle();
		break;
	case 3:
		return CalculateCycle();
		break;
	}
}

int main()
{
	Shapes(readNumber());
}

