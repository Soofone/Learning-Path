#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

bool isPerfectNumber(int Number)
{
    int Sum = 0;

    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
            Sum += i;
    }
    return Number == Sum;
}

void PrintResults(int Number)
{
    if (isPerfectNumber(Number))
        cout << Number << " is Perfect Number.\n";
    else
        cout << Number << " is NOT Perfect Number.\n";
}

int main()
{
    PrintResults(ReadPositiveNumber("Enter a positive number: "));

    return 0;
}