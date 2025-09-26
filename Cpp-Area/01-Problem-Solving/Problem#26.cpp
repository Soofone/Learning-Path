#include <iostream>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Enter a Number: ";
	cin >> Num;
	return Num;
}

void PrintRangeFrom1toN_UsingWhile(int N)
{
	int Counter = 0;

	cout << "Range printed using While Statement:\n";
	while (Counter < N)
	{
		Counter++;
		cout << Counter << endl;
	}

}

void PrintRangeFrom1toN_UsingDoWhile(int N)
{
	int Counter = 0;

	cout << "Range printed using Do..While Statement:\n";
	do
	{
		Counter++;
		cout << Counter << endl;
	} while (Counter < N);
}

void PrintRangeFrom1toN_UsingFor(int N)
{
	cout << "Range printed using For Statement:\n";

	for (int Counter = 1; Counter <= N; Counter++)
	{
		cout << Counter << endl;
	}
}

int main()
{
	int N = ReadNumber();

	PrintRangeFrom1toN_UsingWhile(N);
	PrintRangeFrom1toN_UsingDoWhile(N);
	PrintRangeFrom1toN_UsingFor(N);

	return 0;
}