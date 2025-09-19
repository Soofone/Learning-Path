#include <iostream>
using namespace std;

void ReadNumbers(int& Number1, int& Number2)
{
	cout << "Enter Number 1: ";
	cin >> Number1;

	cout << "Enter Number 2: ";
	cin >> Number2;
}

int MaxOf2Numbers(int Number1, int Number2)
{
	if (Number1 > Number2)
		return Number1;
	else
		return Number2;
}

void PrintResult(int Number)
{
	cout << "\n The Max Number is: " << Number << endl;
}

int main()
{
	int Number1, Number2;
	ReadNumbers(Number1, Number2);
	PrintResult(MaxOf2Numbers(Number1, Number2));

	return 0;
}