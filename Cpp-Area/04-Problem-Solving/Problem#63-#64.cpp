#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct sDate
{
	short Year;
	short Month;
	short Day;
};

vector <string> SplitString(string S1, string Delim)
{
	string sWord = "";
	short pos = 0;
	vector <string> vString;

	while ((pos = S1.find(Delim)) != string::npos)
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

string DateToString(sDate Date)
{
	return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

sDate StringToDate(string DateString)
{
	sDate Date;
	vector <string> vDate;

	vDate = SplitString(DateString, "/");
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string ReadStringDate(string Message)
{
	string DateString = "";

	cout << Message;
	getline(cin >> ws, DateString);
	return DateString;
}

int main()
{
	string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");

	sDate Date = StringToDate(DateString);

	cout << "\nDay: " << Date.Day << endl;
	cout << "Month: " << Date.Month << endl;
	cout << "Year: " << Date.Year << endl;


	cout << "\nYou Entered: " << DateToString(Date) << "\n";


	system("pause>0");
	return 0;
}