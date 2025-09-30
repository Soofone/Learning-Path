#include <iostream>
using namespace std;

struct stPiggyBankContent
{
	int Pennies, Nickels, Dimes, Quarters, Dollars;
};

stPiggyBankContent ReadPiggyBankContent()
{
    stPiggyBankContent PiggyBankContent;

	cout << "Enter the total number of Pennies: ";
    cin >> PiggyBankContent.Pennies;
    cout << "Enter the total number of Nickels: ";
    cin >> PiggyBankContent.Nickels;
    cout << "Enter the total number of Dimes: ";
    cin >> PiggyBankContent.Dimes;
    cout << "Enter the total number of Quarters: ";
    cin >> PiggyBankContent.Quarters;
    cout << "Enter the total number of Dollar bills: ";
    cin >> PiggyBankContent.Dollars;

	return PiggyBankContent;
}

int CalculateTotalPennies(stPiggyBankContent PiggyBankContent)
{
    int TotalPennies = PiggyBankContent.Pennies * 1
        + PiggyBankContent.Nickels * 5
        + PiggyBankContent.Dimes * 10
        + PiggyBankContent.Quarters * 25
        + PiggyBankContent.Dollars * 100;

    return TotalPennies;
}

int main()
{
    int TotalPennies = CalculateTotalPennies(ReadPiggyBankContent());

    cout << endl << "Total Pennies = " << TotalPennies;
    cout << endl << "Total Dollars = $" << (float)TotalPennies / 100 << endl;

    return 0;
}