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

enum enWhatToCount { SmallLetters = 0,  CapitalLetters = 1, All = 2 };

short CountLetters(string S1, enWhatToCount WhatToCount)
{
	short Counter = 0;
	if (WhatToCount == enWhatToCount::All)
	{
		return S1.length();
	}
	for (short i = 0; i < S1.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
		{
			Counter++;
		}
		if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\nString Length: " << CountLetters(S1, enWhatToCount::All);
	cout << "\nCapital Letters Count: " << CountLetters(S1, enWhatToCount::CapitalLetters);
	cout << "\nSmall Letters Count: " << CountLetters(S1, enWhatToCount::SmallLetters);

	system("pause>0");
}