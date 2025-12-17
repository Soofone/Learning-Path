#include <iostream>
using namespace std;

float MySqrt(float Number)
{
    return pow(Number, 0.5);
}

float ReadNumber()
{
    float Number;
    cout << "Enter a float number: ";
    cin >> Number;
    return Number;
}

int main()
{
    float Number = ReadNumber();

    cout << "My MySqrt Result : " << MySqrt(Number) << endl;
    cout << "C++ sqrt Result: " << sqrt(Number) << endl;

    return 0;
}