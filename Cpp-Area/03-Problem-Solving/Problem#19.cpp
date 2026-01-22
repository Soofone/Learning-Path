#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Cols)
{
	cout << "\nMatrix1:\n";
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << '\t';
		}
		cout << '\n';
	}
}

short MinNumberInMatrix(short Matrix[3][3], short Rows, short Cols)
{
	short Number = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Number > Matrix[i][j])
			{
				Number = Matrix[i][j];
			}
		}
	}
	return Number;
}

short MaxNumberInMatrix(short Matrix[3][3], short Rows, short Cols)
{
	short Number = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Number < Matrix[i][j])
			{
				Number = Matrix[i][j];
			}
		}
	}
	return Number;
}

int main()
{
	short Matrix[3][3]{ {77, 5, 12}, {22, 20, 6},{14, 3, 9} };

	PrintMatrix(Matrix, 3, 3);

	cout << "\nMinimum Number is: " << MinNumberInMatrix(Matrix, 3, 3) << endl;
	cout << "\nMaximum Number is: " << MaxNumberInMatrix(Matrix, 3, 3) << endl;

	system("pause>0");
}