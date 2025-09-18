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

int SumOf3Numbers(int Num1, int Num2, int Num3)
{
	return Num1 + Num2 + Num3;
}

void PrintResult(int Total)
{
	cout << "\n Sum = " << Total << endl;
}

int main()
{
	int Num1, Num2, Num3;
	ReadNumbers(Num1, Num2, Num3);
	PrintResult(SumOf3Numbers(Num1, Num2, Num3));

	return 0;
}