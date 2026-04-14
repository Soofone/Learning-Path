#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct sDate
{
	short Year;
	short Month;
	short Day;
};

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsLastDayInMonth(sDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{

	short a = 0, y = 0, m = 0, d = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(sDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(sDate Date)
{
	return (DayOfWeekOrder(Date) == 0);
}

bool IsWeekEnd(sDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 6 || DayIndex == 0);
}

bool IsBusinessDay(sDate Date)
{
	return !IsWeekEnd(Date);
}

short DaysUntilEndOfWeek(sDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilEndOfMonth(sDate Date)
{
	sDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return (GetDifferenceInDays(Date, EndOfMonthDate, true));
}

short DaysUntilEndOfYear(sDate Date)
{
	sDate EndOfYearDate;

	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return (GetDifferenceInDays(Date, EndOfYearDate, true));
}

sDate GetSystemDate()
{
	sDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

int main()
{
	sDate Date = GetSystemDate();

	cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date)) << " , "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

	//------------------------

	cout << "\nIs it End of Week?";
	if (IsEndOfWeek(Date))
		cout << "\nYes it is Sunday, it's end of week.\n";
	else
		cout << "\nNo it's Not end of week.\n";

	//------------------------

	cout << "\nIs it Weekend?";
	if (IsWeekEnd(Date))
		cout << "\nYes it is a week end.\n";
	else
		cout << "\nNo today is " << DayShortName(DayOfWeekOrder(Date)) << ", Not a weekend.\n";

	//------------------------

	cout << "\nIs it Business Day";
	if (IsBusinessDay(Date))
		cout << "\nYes, it is a Business Day.\n";
	else
		cout << "\nNo, it is NOT a business day.\n";

	//------------------------

	cout << "\nDays until end of week  : " << DaysUntilEndOfWeek(Date) << " Days(s).";
	cout << "\nDays until end of month : " << DaysUntilEndOfMonth(Date) << " Days(s).";
	cout << "\nDays until end of year  : " << DaysUntilEndOfYear(Date) << " Days(s).";

	system("pause>0");
	return 0;
}