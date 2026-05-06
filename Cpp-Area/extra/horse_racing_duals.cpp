#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; cin.ignore();
    int arr[n];
    int diff;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; cin.ignore();
    }
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    sort(arr, arr + n);
    diff = arr[1] - arr[0];
    for (int i = 1; i < n - 1; i++)
    {
        int current = abs(arr[i] - arr[i + 1]);
        if (current < diff)
            diff = current;
    }
    cout << diff << endl;
}
