#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
	string S1 = "";
	cout << "Please Enter your String?\n";
	getline(cin, S1);
	return S1;
}

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord = "";

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

int main()
{
	vector <string> vString;

	vString = SplitString(ReadString(), " ");

	cout << "\nTokens = " << vString.size() << endl;

	for (string& s : vString)
	{
		cout << s << endl;
	}

	system("pause>0");
}