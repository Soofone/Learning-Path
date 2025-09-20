#include <iostream>
using namespace std;

void ReadNumbers(int& Num1, int& Num2, int& Num3)
{
	cout << "Enter Number 1: ";
	cin >> Num1;

	cout << "Enter Number 2: ";
	cin >> Num2;

	cout << "Enter Number 3: ";
	cin >> Num3;
}

int MaxOf3Numbers(int Num1, int Num2, int Num3)
{
	if (Num1 > Num2)
	{
		if (Num1 > Num3)
			return Num1;
		else
			return Num3;
	}
	else
	{
		if (Num2 > Num3)
			return Num2;
		else
			return Num3;
	}
}

void PrintResult(int Number)
{
	cout << "\n The Max Number is: " << Number << endl;
}

int main()
{
	int Num1, Num2, Num3;
	ReadNumbers(Num1, Num2, Num3);
	PrintResult(MaxOf3Numbers(Num1, Num2, Num3));

	return 0;
}