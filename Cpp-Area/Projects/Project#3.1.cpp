#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const string FileName = "Clients.txt";

enum enMenuChoice { ShowClientList = 1, AddNewClient = 2, DeleteClient = 3, UpdateClientInfo = 4, FindClient = 5, Exit = 6 };

struct stClient
{
	string AccountNumber = "", PinCode = "", Name = "", Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = false;
};

void PrintMainMenu()
{
	cout << "================================================\n";
	cout << "\t\tMain Menu Screen\n";
	cout << "================================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "================================================\n";
}

short ReadChoice()
{
	short Choice = 0;
	cout << "Choose what do you want to do? [1 to 6]? ";
	cin >> Choice;
	return Choice;
}

vector <string> SplitString(string S1, string Delim = "#//#")
{
	vector <string> vString;
	short pos = 0;
	string sWord = "";
	while ((pos = S1.find(Delim)) != string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}
	return vString;
}

stClient ConvertLineToRecord(string S1, string Delim = "#//#")
{
	stClient Client;
	vector <string> VClientData = SplitString(S1);

	Client.AccountNumber = VClientData[0];
	Client.PinCode = VClientData[1];
	Client.Name = VClientData[2];
	Client.Phone = VClientData[3];
	Client.AccountBalance = stod(VClientData[4]);

	return Client;
}

string ConvertRecordToLine(stClient Client, string Delim = "#//#")
{
	string sLine = "";
	sLine += Client.AccountNumber + Delim;
	sLine += Client.PinCode + Delim;
	sLine += Client.Name + Delim;
	sLine += Client.Phone + Delim;
	sLine += to_string(Client.AccountBalance);
	return sLine;
}

vector <stClient> FillClientsVector()
{
	vector <stClient> vClient;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";
		stClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClient.push_back(Client);
		}
		MyFile.close();
	}
	return vClient;
}

vector <stClient> VectorToFile(vector <stClient> vClient)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		string sLine = "";
		for (stClient& C : vClient)
		{
			if (C.MarkForDelete == false)
			{
				sLine = ConvertRecordToLine(C);
				MyFile << sLine << endl;
			}
		}
		MyFile.close();
	}
	return vClient;
}

//[1] !!
void PrintClientList()
{
	system("cls");
	vector <stClient> vClient = FillClientsVector();
	cout << "\n\t\tClient List (" << vClient.size() << ") Client(s).\n";
	cout << "\n_____________________________________________________________________________________________________\n\n";
	cout << "| " << setw(17) << left << "Account Number ";
	cout << "| " << setw(11) << left << "Pin Code ";
	cout << "| " << setw(40) << left << "Client Name ";
	cout << "| " << setw(14) << left << "Phone ";
	cout << "| " << setw(14) << left << "Balance ";
	cout << "\n_____________________________________________________________________________________________________\n\n";
	for (stClient& C : vClient)
	{
		cout << "| " << setw(17) << left << C.AccountNumber;
		cout << "| " << setw(11) << left << C.PinCode;
		cout << "| " << setw(40) << left << C.Name;
		cout << "| " << setw(14) << left << C.Phone;
		cout << "| " << setw(14) << left << C.AccountBalance;
		cout << endl;
	}
	cout << "_____________________________________________________________________________________________________\n\n";
	system("pause");
}

bool IsDuplicated(stClient NewClient, vector <stClient> vClient)
{
	for (stClient& C : vClient)
	{
		if (NewClient.AccountNumber == C.AccountNumber)
		{
			return true;
		}
	}
	return false;
}

//[2] !!
void AddClient()
{
	char AddMore = 'y';
	do
	{
		system("cls");
		vector <stClient> vClient = FillClientsVector();
		stClient NewClient;
		cout << "\n--------------------------------------\n";
		cout << "\tAdd New Clients Screen";
		cout << "\n--------------------------------------\n";
		cout << "Adding New Client:\n";
		cout << "\nEnter Account Number? ";
		getline(cin >> ws, NewClient.AccountNumber);
		while (IsDuplicated(NewClient, vClient))
		{
			cout << "\nClient with [" << NewClient.AccountNumber << "] already exists, Enter another Account Number? ";
			getline(cin >> ws, NewClient.AccountNumber);
		}
		cout << "Enter PinCode? ";
		getline(cin, NewClient.PinCode);
		cout << "Enter Name? ";
		getline(cin, NewClient.Name);
		cout << "Enter Phone? ";
		getline(cin, NewClient.Phone);
		cout << "Enter Account Balance? ";
		cin >> NewClient.AccountBalance;

		vClient.push_back(NewClient);
		VectorToFile(vClient);
		cout << "\nClient Added Succeccfuly, do you want to add more clients? Y/N? ";
		cin >> AddMore;
	} while (AddMore == 'y' || AddMore == 'Y');
}

bool FindClientByAccountNum(string AccountNum, stClient& Client, vector <stClient> vClient)
{

	for (stClient& C : vClient)
	{
		if (C.AccountNumber == AccountNum)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void PrintClientCard(stClient Client)
{
	cout << "\nThe following are the client details:";
	cout << "\n--------------------------------------";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code      : " << Client.PinCode;
	cout << "\nName          : " << Client.Name;
	cout << "\nPhone         : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n--------------------------------------\n";
}

bool MarkClientsForDelete(string AcountNum, vector <stClient>& vClient)
{
	fstream MyFile;
	MyFile.open(FileName, ios::app);
	if (MyFile.is_open())
	{
		for (stClient& C : vClient)
		{
			if (C.AccountNumber == AcountNum)
			{
				C.MarkForDelete = true;
				return true;
			}
		}
		MyFile.close();
	}
	return false;
}

//[3] !!
void DelClient()
{
	system("cls");
	vector <stClient> vClient = FillClientsVector();
	stClient Client;
	string AcountNum = "";
	char Delete = 'n';
	cout << "\n--------------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n--------------------------------------\n";

	cout << "\nPlease Enter Account Number? ";
	getline(cin >> ws, AcountNum);

	if (FindClientByAccountNum(AcountNum, Client, vClient))
	{
		PrintClientCard(Client);
		cout << "\nAre you sure you want delete this client? Y/N? ";
		cin >> Delete;
		if (Delete == 'y' || Delete == 'Y')
		{
			MarkClientsForDelete(AcountNum, vClient);
			VectorToFile(vClient);
			vClient = FillClientsVector();
			cout << "\nClient Deleted Successfuly.\n";
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AcountNum << ") in Not Found!\n";
	}
}

stClient ChangeClientData(string AcountNum)
{
	stClient Client;
	Client.AccountNumber = AcountNum;
	cout << "Enter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name?  ";
	getline(cin, Client.Name);
	cout << "Enter Phone?  " << Client.Phone;
	getline(cin, Client.Phone);
	cout << "Account Balance?  ";
	cin >> Client.AccountBalance;
	return Client;
}

//[4] !!
void UpdateClient()
{
	system("cls");
	vector <stClient> vClient = FillClientsVector();
	stClient Client;
	string AcountNum = "";
	char Update = 'n';
	cout << "\n-----------------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-----------------------------------------\n";

	cout << "\nPlease Enter Account Number? ";
	getline(cin >> ws, AcountNum);

	if (FindClientByAccountNum(AcountNum, Client, vClient))
	{
		PrintClientCard(Client);
		cout << "\nAre you sure you want update this client? Y/N? ";
		cin >> Update;
		if (Update == 'y' || Update == 'Y')
		{
			for (stClient& C : vClient)
			{
				if (C.AccountNumber == AcountNum)
				{
					C = ChangeClientData(AcountNum);
					break;
				}
			}
			VectorToFile(vClient);
			vClient = FillClientsVector();
			cout << "\nClient Updated Successfuly.\n";
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AcountNum << ") in Not Found!\n";
	}
}

//[5] !!
void SearchClient()
{
	system("cls");
	vector <stClient> vClient = FillClientsVector();
	stClient Client;
	string AcountNum = "";
	cout << "\n--------------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n--------------------------------------\n";
	cout << "\nPlease Enter Account Number? ";
	getline(cin >> ws, AcountNum);
	if (FindClientByAccountNum(AcountNum, Client, vClient))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AcountNum << ") in Not Found!\n";
	}
}

//[6] !!
void ProgramEnds()
{
	system("cls");
	cout << "\n--------------------------------------\n";
	cout << "\tProgram Ends :-)";
	cout << "\n--------------------------------------\n";
}

int main()
{
	PrintMainMenu();
	short Choice = ReadChoice();

	switch (Choice)
	{
		{
			case short(enMenuChoice::ShowClientList) :
				PrintClientList();
				break;
		}

		{
			case short(enMenuChoice::AddNewClient) :
				AddClient();
				break;
		}

		{
			case short(enMenuChoice::DeleteClient) :
				DelClient();
				break;
		}

		{
			case short(enMenuChoice::UpdateClientInfo) :
				UpdateClient();
				break;
		}

		{
			case short(enMenuChoice::FindClient) :
				SearchClient();
				break;
		}

		{
			case short(enMenuChoice::Exit) :
				ProgramEnds();
				break;
		}
	}

	system("pause>0");
	return 0;
}