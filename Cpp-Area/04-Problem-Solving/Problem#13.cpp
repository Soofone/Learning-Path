#include <iostream>
using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Please enter a year? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day = 0;
	cout << "Please enter a Day? ";
	cin >> Day;
	return Day;
}

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate ReadFullDate()
{
	sDate Date;
	cout << '\n';
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int main()
{
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();


	if (IsDate1BeforeDate2(Date1, Date2))
		cout << "\nYes, Date1 is Less than Date2.\n";
	else
		cout << "\nNo, Date1 is not Less than Date2.\n";


	system("pause>0");
	return 0;
}