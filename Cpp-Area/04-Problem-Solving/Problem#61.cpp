#include <iostream>
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

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
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

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(sDate Date1, sDate Date2)
{

	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

int PeriodLengthInDays(sPeriod Period, bool IncludeEndDay = false)
{
	return GetDifferenceInDays(Period.StartPeriod, Period.EndPeriod, IncludeEndDay);
}

bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
{
	short Days = 0;

	if ((CompareDates(Period2.EndPeriod, Period1.StartPeriod) == enDateCompare::Before
		||
		CompareDates(Period2.StartPeriod, Period1.EndPeriod) == enDateCompare::After))
		return false;
	else
		return true;

}

bool IsDateInPeriod(sDate Date, sPeriod Period)
{
	return !(CompareDates(Date, Period.StartPeriod) == enDateCompare::Before
		||
		CompareDates(Date, Period.EndPeriod) == enDateCompare::After);
}

int CountOverlapDays(sPeriod Period1, sPeriod Period2)
{
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int OverlapDays = 0;

	if (!IsOverlapPeriods(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforeDate2(Period1.StartPeriod, Period1.EndPeriod))
		{
			if (IsDateInPeriod(Period1.StartPeriod, Period2))
				OverlapDays++;

			Period1.StartPeriod = IncreaseDateByOneDay(Period1.StartPeriod);
		}
	}

	else
	{
		while (IsDate1BeforeDate2(Period2.StartPeriod, Period2.EndPeriod))
		{
			if (IsDateInPeriod(Period2.StartPeriod, Period1))
				OverlapDays++;

			Period2.StartPeriod = IncreaseDateByOneDay(Period2.StartPeriod);
		}
	}
	return OverlapDays;
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

int main()
{
	cout << "\nEnter Period 1 :";
	sPeriod Period1 = ReadPeriod();

	cout << "\nEnter Period 2 :";
	sPeriod Period2 = ReadPeriod();

	cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2);

	system("pause>0");
	return 0;
}