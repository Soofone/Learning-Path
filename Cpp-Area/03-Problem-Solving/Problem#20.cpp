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

bool IsPalindromeMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols / 2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
				return false;
		}
	}
	return true;
}

int main()
{
	short Matrix[3][3]{ {1,2,1}, {5,5,5}, {7,3,7} };

	PrintMatrix(Matrix, 3, 3);

	if (IsPalindromeMatrix(Matrix, 3, 3))
		cout << "\nYES: Matrix is Palindrome.\n";
	else
		cout << "\nNO: Matrix is NOT Palindrome.\n";

	system("pause>0");
}