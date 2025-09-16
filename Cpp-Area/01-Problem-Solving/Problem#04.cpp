#include <iostream>
using namespace std;

struct stInfo
{
	int	Age;
	bool HasDriverLicense;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Enter your Age: ";
	cin >> Info.Age;

	cout << "Do you Have Driver License? (yes: 1 / no: 0): ";
	cin >> Info.HasDriverLicense;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	return (Info.Age > 21 && Info.HasDriverLicense);
}

void PrintResult(stInfo Info)
{
	if (IsAccepted(Info))
		cout << "\n Hired!" << endl;
	else
		cout << "\n Rejected!" << endl;
}

int main()
{
	PrintResult(ReadInfo());

	return 0;
}