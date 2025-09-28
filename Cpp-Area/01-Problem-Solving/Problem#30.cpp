#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int	Num;
	do
	{
		cout << Message;
		cin >> Num;
	} while (Num < 0);

	return Num;
}

int Factorial(int N)
{
	int F = 1;
	for (int Counter = N; Counter >= 1; Counter--)
	{
		F *= Counter;
	}
	return F;
}

int main()
{
	cout << "Factorial = " << Factorial(ReadPositiveNumber("Enter a positive number N: ")) << endl;
	return 0;
}
