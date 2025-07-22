#include <iostream>
using namespace std;

enum enNumberType { Odd = 1, Even = 2 };

int ReadNumber()
{
	int Number;

	cout << "Please Enter a number?" << endl;
	cin >> Number;
	return Number;
}

enNumberType CheckNumberType(int Number)
{
	int Result = Number % 2;

	if (Result == 0)
	{
		return enNumberType::Even;
	}
	else
	{
		return enNumberType::Odd;
	}
}

void PrintNumber(enNumberType NumberType)
{
	if (NumberType == enNumberType::Even)
	{
		cout << "\n Number is Even. \n" << endl;
	}
	else
	{
		cout << "\n Number is Odd. \n" << endl;
	}
}

int main()
{
	PrintNumber(CheckNumberType(ReadNumber()));

	return 0;
}