#include <iostream>
using namespace std;

void ReadNumbers(float& A, float& B)
{
	cout << "Enter rectangle width A: ";
	cin >> A;

	cout << "Enter rectangle length B: ";
	cin >> B;
}

float CalculateRectangleArea(float A, float B)
{
	return A * B;
}

void PrintResult(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;
}

int main()
{
	float A, B;
	ReadNumbers(A, B);
	PrintResult(CalculateRectangleArea(A, B));

	return 0;
}