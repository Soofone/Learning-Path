#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 6;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;

}

bool IsPalindromArray(int SourceArr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (SourceArr[i] != SourceArr[arrLength - 1 - i])
            return 0;
    }
    return 1;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[100], arrLength = 0;

    FillArray(arr, arrLength);

    IsPalindromArray(arr, arrLength);

    cout << "Array Element: ";
    PrintArray(arr, arrLength);

    if (IsPalindromArray(arr, arrLength))
        cout << "\nIts a Palindrom array\n";
    else
        cout << "\nNot a Palindrom array\n";

    return 0;
}