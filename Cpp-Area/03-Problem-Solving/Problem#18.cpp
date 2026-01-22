#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << '\t';
		}
		cout << '\n';
	}
}

bool IsNumberInMatrix(short Matrix[3][3], short Number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				return true;
			}
		}
	}
	return false;
}

void PrintIntersectedNumber(short Matrix1[3][3], short Matrix2[3][3], short Rows, short Cols)
{
	short Number = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Number = Matrix1[i][j];
			if (IsNumberInMatrix(Matrix2, Number, 3, 3))
			{
				cout << setw(3) << Number << '\t';
			}
		}
	}
}

int main()
{
	short Matrix1[3][3]{ {77, 5, 12}, {22, 20, 1}, {1, 0, 9} };
	short Matrix2[3][3]{ {5, 80, 90}, {22, 77, 1}, {10, 8, 33} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected Numbers are:\n";
	PrintIntersectedNumber(Matrix1, Matrix2, 3, 3);

	system("pause>0");
}