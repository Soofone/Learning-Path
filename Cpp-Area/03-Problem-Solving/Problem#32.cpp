#include <iostream>
#include <string>
using namespace std;

char ReadChar()
{
	char Ch1 = ' ';
	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1;

	return Ch1;
}

bool IsVowel(char Char1)
{
	Char1 = tolower(Char1);

	return ((Char1 == 'a') || (Char1 == 'e') || (Char1 == 'i') || (Char1
		== 'o') || (Char1 == 'u'));
}

int main()
{
	char Char1 = ReadChar();

	if (IsVowel(Char1))
	{
		cout << "\nYES Letter \'" << Char1 << "\' is vowel.\n";
	}
	else
	{
		cout << "\nNO Letter \'" << Char1 << "\' is NOT vowel.\n";
	}

	system("pause>0");
}