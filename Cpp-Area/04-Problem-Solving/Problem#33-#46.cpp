#include <iostream>
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

//[01] !!
sDate DecreaseDateByOneDay(sDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

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

sDate ReadFullDate()
{
	sDate Date;
	cout << '\n';
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

//[2] !!
sDate DecreaseDateByXDays(short Days, sDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

//[3] !!
sDate DecreaseDateByOneWeek(sDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

//[4] !!
sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

//[5] !!
sDate DecreaseDateByOneMonth(sDate Date)
{

	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

//[6] !!
sDate DecreaseDateByXMonths(short Months, sDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

//[7] !!
sDate DecreaseDateByOneYear(sDate Date)
{
	Date.Year--;
	return Date;
}

//[8] !!
sDate DecreaseDateByXYears(short Years, sDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

//[9] !!
sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
{
	Date.Year -= Years;
	return Date;
}

//[10] !!
sDate DecreaseDateByOneDecade(sDate Date)
{
	Date.Year -= 10;
	return Date;
}

//[11] !!
sDate DecreaseDateByXDecades(short Decade, sDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

//[12] !!
sDate DecreaseDateByXDecadesFaster(short Decade, sDate Date)
{
	Date.Year -= Decade * 10;
	return Date;
}

//[13] !!
sDate DecreaseDateByOneCentury(sDate Date)
{
	Date.Year -= 100;
	return Date;
}

//[14] !!
sDate DecreaseDateOneMillennium(sDate Date)
{
	Date.Year -= 1000;
	return Date;
}

int main()
{
	sDate Date = ReadFullDate();

	cout << "\nDate After:\n";

	Date = DecreaseDateByOneDay(Date);
	cout << "\n01-Substracting one day is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByXDays(10, Date);
	cout << "02-Substracting 10 days is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByOneWeek(Date);
	cout << "03-Substracting one week is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByXWeeks(10, Date);
	cout << "04-Substracting 10 weeks is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByOneMonth(Date);
	cout << "05-Substracting one months is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByXMonths(5, Date);
	cout << "06-Substracting 5 months is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByOneYear(Date);
	cout << "07-Substracting one year is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByXYears(10, Date);
	cout << "08-Substracting 10 years is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByXYearsFaster(10, Date);
	cout << "09-Substracting 10 years (faster) is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByOneDecade(Date);
	cout << "10-Substracting one decade is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByXDecades(10, Date);
	cout << "11-Substracting 10 decades is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByXDecadesFaster(10, Date);
	cout << "11-Substracting 10 decades (faster) is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateByOneCentury(Date);
	cout << "13-Substracting one century is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = DecreaseDateOneMillennium(Date);
	cout << "14-Substracting one millennium is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	system("pause>0");
	return 0;
}