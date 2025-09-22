#include <iostream>
using namespace std;

float ReadRadius()
{
	float R;

	cout << "Enter Radius R: ";
	cin >> R;
	return R;
}

float CircleArea(float R)
{
	const float PI = 3.141592653589793238;
	float Area = pow(R, 2) * PI;
	return Area;
}

void PrintResult(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintResult(CircleArea(ReadRadius()));

	return 0;
}