#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 40;
    arr[9] = 90;
}

void AddArrayElements(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

short FindNumberPositionInArray(int arr[100], int arrLength, int  NumberToSearch)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == NumberToSearch)
            return i;

    }
    return -1;
}

bool IsNumberInArray(int arr[100], int arrLength, int  NumberToSearch)
{
    return FindNumberPositionInArray(arr, arrLength, NumberToSearch) != -1;
}

void CopyDistinctNumbersToArray(int arr[100], int DistArr[100], int arrLength, int& DistArrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (!IsNumberInArray(DistArr, arrLength, arr[i]))
        {
            AddArrayElements(arr[i], DistArr, DistArrLength);
        }
    }

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
    int arrLenght = 0, DistArrLength = 0;
    int arr[100];
    FillArray(arr, arrLenght);

    int DistinctArr[100];
    CopyDistinctNumbersToArray(arr, DistinctArr, arrLenght, DistArrLength);

    cout << "\nArray[1] Elements: ";
    PrintArray(arr, arrLenght);

    cout << "\nDistinct numbers: ";
    PrintArray(DistinctArr, DistArrLength);

    return 0;
}