#include <iostream>
using namespace std;

int ReadNumber()
{
	int	Number;
	cout << "Enter a Number: ";
	cin >> Number;

	return Number;
}

int ReadPower()
{
	int	Power;

	cout << "Enter a Power: ";
	cin >> Power;

	return Power;
}

int PowerOfM(int Number, int M)
{
	if (M == 0)
		return 1;
	int P = 1;
	for (int i = 1; i <= M; i++)
	{
		P *= Number;
	}
	return P;
}

int main()
{
	cout << endl << "Result = " << PowerOfM(ReadNumber(), ReadPower()) << endl;

	return 0;
}