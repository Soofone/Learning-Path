#include <iostream>
using namespace std;

enum enNumberType { Odd = 1, Even = 2 };

int ReadNumber()
{
	int	Num;

	cout << "Enter a Number: ";
	cin >> Num;
	return Num;
}

enNumberType CheckOddOrEven(int Number)
{
	if (Number % 2 != 0)
		return enNumberType::Odd;
	else
		return enNumberType::Even;
}

int SumOddNumbersFrom1ToN_UsingFor(int N)
{
	int Sum = 0;
	cout << "\nSum odd numbers using For Statement:\n";

	for (int Counter = 1; Counter <= N; Counter++)
	{
		if (CheckOddOrEven(Counter) == enNumberType::Odd)
			Sum += Counter;
	}
	return Sum;
}

int SumOddNumbersFrom1ToN_UsingWhile(int N)
{
	int Sum = 0;
	int Counter = 0;

	cout << "\nSum odd numbers using While Statement:\n";
	while (Counter < N)
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enNumberType::Odd)
			Sum += Counter;
	}
	return Sum;
}

int SumOddNumbersFrom1ToN_UsingDoWhile(int N)
{
	int Sum = 0;
	int Counter = 0;

	cout << "\nSum odd numbers using Do..While Statement:\n";
	while (Counter < N)
	do
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enNumberType::Odd)
			Sum += Counter;
	} while (Counter < N);
	return Sum;
}

void PrintSum(int Sum)
{
	cout << "Sum = " << Sum << endl;
}

int main()
{
	int N = ReadNumber();

	PrintSum(SumOddNumbersFrom1ToN_UsingWhile(N));
	PrintSum(SumOddNumbersFrom1ToN_UsingDoWhile(N));
	PrintSum(SumOddNumbersFrom1ToN_UsingFor(N));
	return 0;
}