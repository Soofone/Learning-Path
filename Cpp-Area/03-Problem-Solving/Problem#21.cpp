#include <iostream>
using namespace std;

void PrintFibonacciUsingLoop(short Number)
{
	short Prev2 = 0, Prev1 = 1, Sum = 0;

	cout << "1    ";
	for (short i = 2; i <= Number; i++)
	{
		Sum = Prev2 + Prev1;
		cout << Sum << "    ";

		Prev2 = Prev1;
		Prev1 = Sum;
	}
}

int main()
{

	PrintFibonacciUsingLoop(10);

	system("pause>0");
}