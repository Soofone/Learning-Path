#include <iostream>
using namespace std;

void ReadTriangleData(float& A, float& B, float& C)
{
	cout << "Enter triangle side A: ";
	cin >> A;

	cout << "Enter triangle base B: ";
	cin >> B;

	cout << "Enter triangle side C: ";
	cin >> C;
}

float CircleAreaByATriangle(float A, float B, float C)
{
	float P;
	float T;
	float Area;
	const float PI = 3.141592653589793238;

	P = (A + B + C) / 2;
	T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
	Area = PI * pow(T, 2);
	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	float A, B, C;
	ReadTriangleData(A, B, C);
	PrintResult(CircleAreaByATriangle(A, B, C));

	return 0;
}