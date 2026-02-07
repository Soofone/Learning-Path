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

void PrintEachWordInString(string S1)
{
	string delim = " ", sWord = "";
	short pos = 0;

	cout << "\nYour string words are:\n\n";

	while ((pos = S1.find(delim)) != string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			cout << sWord << endl;
		}
		S1.erase(0, pos + delim.length());
	}

	if (S1 != "")
	{
		cout << S1 << endl;
	}
}

int main()
{
	PrintEachWordInString(ReadString());

	system("pause>0");
}