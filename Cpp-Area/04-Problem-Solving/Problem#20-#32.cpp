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
sDate IncreaseDateByXDays(short Days, sDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

//[3] !!
sDate IncreaseDateByOneWeek(sDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

//[4] !!
sDate IncreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

//[5] !!
sDate IncreaseDateByOneMonth(sDate Date)
{

	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

//[6] !!
sDate IncreaseDateByXMonths(short Months, sDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

//[7] !!
sDate IncreaseDateByOneYear(sDate Date)
{
	Date.Year++;
	return Date;
}

//[8] !!
sDate IncreaseDateByXYears(short Years, sDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

//[9] !!
sDate IncreaseDateByXYearsFaster(short Years, sDate Date)
{
	Date.Year += Years;
	return Date;
}

//[10] !!
sDate IncreaseDateByOneDecade(sDate Date)
{
	Date.Year += 10;
	return Date;
}

//[11] !!
sDate IncreaseDateByXDecades(short Decade, sDate Date)
{
	for (short i = 1; i <= Decade * 10; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

//[12] !!
sDate IncreaseDateByXDecadesFaster(short Decade, sDate Date)
{
	Date.Year += Decade * 10;
	return Date;
}

//[13] !!
sDate IncreaseDateByOneCentury(sDate Date)
{
	Date.Year += 100;
	return Date;
}

//[14] !!
sDate IncreaseDateOneMillennium(sDate Date)
{
	Date.Year += 1000;
	return Date;
}

int main()
{
	sDate Date = ReadFullDate();

	cout << "\nDate After:\n";

	Date = IncreaseDateByOneDay(Date);
	cout << "\n01-Adding one day is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByXDays(10, Date);
	cout << "02-Adding 10 days is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByOneWeek(Date);
	cout << "03-Adding one week is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByXWeeks(10, Date);
	cout << "04-Adding 10 weeks is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByOneMonth(Date);
	cout << "05-Adding one months is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByXMonths(5, Date);
	cout << "06-Adding 5 months is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByOneYear(Date);
	cout << "07-Adding one year is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByXYears(10, Date);
	cout << "08-Adding 10 years is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByXYearsFaster(10, Date);
	cout << "09-Adding 10 years (faster) is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByOneDecade(Date);
	cout << "10-Adding one decade is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByXDecades(10, Date);
	cout << "11-Adding 10 decades is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByXDecadesFaster(10, Date);
	cout << "11-Adding 10 decades (faster) is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateByOneCentury(Date);
	cout << "13-Adding one century is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	Date = IncreaseDateOneMillennium(Date);
	cout << "14-Adding one millennium is: " << Date.Day << '/' << Date.Month << '/' << Date.Year << '\n';

	system("pause>0");
	return 0;
}