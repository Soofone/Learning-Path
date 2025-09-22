#include <iostream>
using namespace std;

void ReadNumbers(float& A, float& H)
{
	cout << "Enter rectangle width A: ";
	cin >> A;

	cout << "Enter rectangle length H: ";
	cin >> H;
}

float TriangleArea(float A, float H)
{
	float Area = (A / 2) * H;
	return Area;
}

void PrintResult(float Area)
{
	cout << "\nTriangle Area = " << Area << endl;
}

int main()
{
	float A, H;
	ReadNumbers(A, H);
	PrintResult(TriangleArea(A, H));

	return 0;
}