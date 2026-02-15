#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string ReplaceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = S1.find(StringToReplace);
	}
	return S1;
}

int main()
{
	string S1 = "Welcome to Morocco, Morocco is a nice country.";
	string StringToReplace = "Morocco";
	string ReplaceTo = "Germany";

	cout << "\nOriginal String:\n" << S1;
	cout << "\n\nString After Replace:\n";
	cout << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);

	system("pause>0");
}