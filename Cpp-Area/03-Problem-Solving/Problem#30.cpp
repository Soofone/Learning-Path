#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Please Enter Your String?\n";
	getline(cin, S1);

	return S1;
}

char ReadChar()
{
	char Ch1 = ' ';
	cout << "\nPlease Enter a Character?\n";
	cin >> Ch1;

	return Ch1;
}

short CountLetter(string S1, char Letter)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] == Letter)
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();
	char Char1 = ReadChar();

	cout << "\nLetter \'" << Char1 << "\' Count = " << CountLetter(S1, Char1);

	system("pause>0");
}