#include <cmath>
#include <string>
#include <iostream>
using namespace std;
short ReadNumber(short& N)
{
	cout << "please enter number " << endl;
	cin >> N;
	return N;
}
void CreateNestedLoopTraingle(short& N)
{
	short sum = 0;
	for (short i = 1; i >= N; i++)
	{
		sum += i;
		for (short j=1; j<=N;j++)
		{

			cout << "*";
		}
		cout << endl;

	}

	cout << "Total stars printed :" << sum;
}

int main()
{
	short N = 0;
	short sum;
	ReadNumber(N);
	CreateNestedLoopTraingle(N);

}