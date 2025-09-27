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

int SumEvenNumbersFrom1ToN_UsingFor(int N)
{
	int Sum = 0;
	cout << "\nSum even numbers using For Statement:\n";

	for (int Counter = 1; Counter <= N; Counter++)
	{
		if (CheckOddOrEven(Counter) == enNumberType::Even)
			Sum += Counter;
	}
	return Sum;
}

int SumEvenNumbersFrom1ToN_UsingWhile(int N)
{
	int Sum = 0;
	int Counter = 0;

	cout << "\nSum even numbers using While Statement:\n";
	while (Counter < N)
	{
		Counter++;
		if (CheckOddOrEven(Counter) == enNumberType::Even)
			Sum += Counter;
	}
	return Sum;
}

int SumEvenNumbersFrom1ToN_UsingDoWhile(int N)
{
	int Sum = 0;
	int Counter = 0;

	cout << "\nSum even numbers using Do..While Statement:\n";
	while (Counter < N)
		do
		{
			Counter++;
			if (CheckOddOrEven(Counter) == enNumberType::Even)
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

	PrintSum(SumEvenNumbersFrom1ToN_UsingWhile(N));
	PrintSum(SumEvenNumbersFrom1ToN_UsingDoWhile(N));
	PrintSum(SumEvenNumbersFrom1ToN_UsingFor(N));
	return 0;
}