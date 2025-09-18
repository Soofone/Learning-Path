#include <iostream>
using namespace std;

void ReadMarks(int& Mark1, int& Mark2, int& Mark3)
{
	cout << "Enter Mark 1: ";
	cin >> Mark1;

	cout << "Enter Mark 2: ";
	cin >> Mark2;

	cout << "Enter Mark 3: ";
	cin >> Mark3;
}

int SumOf3Marks(int Mark1, int Mark2, int Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
	return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

void PrintResult(float Average)
{
	cout << "\n The Average is: " << Average << endl;
}

int main()
{
	int Mark1, Mark2, Mark3;

	ReadMarks(Mark1, Mark2, Mark3);
	PrintResult(CalculateAverage(Mark1, Mark2, Mark3));

	return 0;
}