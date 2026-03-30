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

int main()
{
	sDate Date = ReadFullDate();
	Date = IncreaseDateByOneDay(Date);

	cout << "\nDate after adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;


	system("pause>0");
	return 0;
}