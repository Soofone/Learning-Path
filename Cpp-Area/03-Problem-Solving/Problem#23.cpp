#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter your Text?\n";
	getline(cin, S1);

	return S1;
}

void PrintFristLetterOfEachWord(string S1)
{
	cout << "\nFirst Letters of This String:\n";
	bool isFirstLetter = true;
 
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			cout << S1[i] << endl;
		}
		isFirstLetter = (S1[i] == ' ' ? true : false);
	}
}

int main()
{
	PrintFristLetterOfEachWord(ReadString());

	system("pause>0");
}