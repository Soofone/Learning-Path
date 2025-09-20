#include <iostream>
using namespace std;

void ReadNumbers(int& Num1, int& Num2)
{
	cout << "Enter Number 1: ";
	cin >> Num1;

	cout << "Enter Number 2: ";
	cin >> Num2;

}

void Swap(int& Num1, int& Num2)
{
	int Temp;

	Temp = Num1;
	Num1 = Num2;
	Num2 = Temp;
}

void PrintNumbers(int Num1, int Num2)
{
	cout << "\nNumber 1 = " << Num1 << endl;
	cout << "Number 2 = " << Num2 << endl;
}

int main()
{
	int Num1, Num2;
	ReadNumbers(Num1, Num2);

	PrintNumbers(Num1, Num2);
	Swap(Num1, Num2);
	PrintNumbers(Num1, Num2);

	return 0;
}