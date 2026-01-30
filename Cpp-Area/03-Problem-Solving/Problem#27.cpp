#include <iostream>
#include <string>
using namespace std;

char ReadChar()
{
	char Ch1 = ' ';
	cout << "Please Enter a Character?\n";
	cin >> Ch1;

	return Ch1;
}

char InvertLetterCase(char Char1)
{
	return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

int main()
{
	char Ch1 = ReadChar();
	cout << "\nChar After Inverting Case:\n";

	Ch1 = InvertLetterCase(Ch1);
	cout << Ch1 << endl;

	system("pause>0");
}