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

short CapitalLettersCount(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

short SmallLettersCount(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\nString Length: " << S1.length();
	cout << "\nCapital Letters Count: " << CapitalLettersCount(S1);
	cout << "\nSmall Letters Count: " << SmallLettersCount(S1);

	system("pause>0");
}