#include <iostream>
#include <string>
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
	cout << "\nPlease enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day = 0;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}

short DayOfWeekOrder(short Year, short Month, short Day)
{

	short a = 0, y = 0, m = 0, d = 0;

	 a = (14 - Month) / 12;
	 y = Year - a;
	 m = Month + (12 * a) - 2;

	 return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	
	return arrDayNames[DayOfWeekOrder];
}

int main()
{

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOfWeekOrder(Year, Month, Day);
	cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Year, Month, Day));

	system("pause>0");
	return 0;
}