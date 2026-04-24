#include <iostream>
#include <string>
using namespace std;

struct sDate
{
	short Year;
	short Month;
	short Day;
};

struct sPeriod
{
	sDate StartPeriod;
	sDate EndPeriod;
};

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

short ReadYear()
{
	short Year = 0;
	cout << "Please enter a Year? ";
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

sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

sPeriod ReadPeriod()
{
	sPeriod Period;

	cout << "\nEnter Start Date:\n\n";
	Period.StartPeriod = ReadFullDate();

	cout << "\nEnter End Date:\n\n";
	Period.EndPeriod = ReadFullDate();

	return Period;
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(sDate Date1, sDate Date2)
{

	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
{
	if (CompareDates(Period2.EndPeriod, Period1.StartPeriod) == enDateCompare::Before
		||
		CompareDates(Period2.StartPeriod, Period1.EndPeriod) == enDateCompare::After)
		return false;
	else
		return true;
}

int main()
{
	cout << "\nEnter Period 1:";
	sPeriod Period1 = ReadPeriod();

	cout << "\nEnter Period 2:";
	sPeriod Period2 = ReadPeriod();

	if (IsOverlapPeriods(Period1, Period2))
		cout << "\nYes, Periods Overlap.\n";
	else
		cout << "\nNo, Periods do not Overlap.\n";


	system("pause>0");
	return 0;
}