#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    int num;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        arr[i] = t;
    }
    num = arr[0];
    for (int i = 1; i < n; i++) {
        if (abs(num) == abs(arr[i]))
        {
            if (arr[i] > num)
                num = arr[i];
        }
        else if (abs(num) > abs(arr[i]))
            num = arr[i];
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cout << num << endl;
    // cout << "result" << endl;
}
