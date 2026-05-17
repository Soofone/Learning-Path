#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

void PrintMainMenuScreen();

void PrintManageUsersMenuScreen();

const string FileName = "Clients.txt";

const string FileName2 = "Users.txt";

struct stLogin
{
	string Username, Password;
	int Permissions;
	bool MarkForDelete = 0;
};

vector<stLogin> LoadLoginAccountsFromFile();

stLogin CurrentUser;

struct stClient
{
	string AccountNumber = "", PinCode = "", Name = "", Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = 0;
};

enum enMainMenuOptions { DisplayClientList = 1, AddNewClients = 2, DeleteClient = 3, eUpdateClientInfo = 4, eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLogout = 8 };

enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eMainMenu = 4 };

enum enManageUsersMenuOptions { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, MainMenu = 6 };

struct stManageUsersAccess
{
	char GiveFullAccess, stListClient, stAddNewClient, stDeleteClient, stUpdateClient, stFindClient, stTransactions, stManageUsers;
};

enum eManageUsersAccess { eeListClient = 1, eeAddNewClient = 2, eeDeleteClient = 4, eeUpdateClient = 8, eeFindClient = 16, eeTransactions = 32, eeManageUsers = 64 };

vector<string> SplitString(string S1, string Delim = " | ")
{
	vector<string> vString;
	short pos = 0;
	string sword;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sword = S1.substr(0, pos);
		if (sword != "")
			vString.push_back(sword);
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
		vString.push_back(S1);
	return vString;
}

stLogin ConvertLineToRecord2(string Line)
{
	stLogin Login;
	vector<string> vString = SplitString(Line);

	Login.Username = vString[0];
	Login.Password = vString[1];
	Login.Permissions = stoi(vString[2]);
	return Login;
}

stClient ConvertLineToRecord(string Line)
{
	stClient Client;
	vector<string> vString = SplitString(Line);

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.AccountBalance = stoi(vString[4]);
	return Client;
}

string ConvertRecordToLine(stClient Client, string Delim = " | ")
{
	string Line = "";

	Line += Client.AccountNumber + Delim;
	Line += Client.PinCode + Delim;
	Line += Client.Name + Delim;
	Line += Client.Phone + Delim;
	Line += to_string(Client.AccountBalance);
	return Line;
}

string ConvertRecordToLine2(stLogin stLogin, string Delim = " | ")
{
	string Line = "";

	Line += stLogin.Username + Delim;
	Line += stLogin.Password + Delim;
	Line += to_string(stLogin.Permissions);
	return Line;
}

vector<stClient> LoadDataFromFile()
{
	string Line = "";
	stClient Client;
	fstream MyFile;
	vector<stClient> vClient;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClient.push_back(Client);
		}
		MyFile.close();
	}
	return vClient;
}

void PrintClientLine(stClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.AccountBalance;
	cout << endl;
}

void ShowClientList()
{
	vector<stClient> vClient = LoadDataFromFile();

	cout << "\n\t\t\t\tClient List (" << vClient.size() << ") Client(s).\n";
	cout << "________________________________________________________________________________________________\n\n";
	cout << "| " << setw(15) << left << "Account Number ";
	cout << "| " << setw(10) << left << "Pin Code ";
	cout << "| " << setw(40) << left << "Client Name ";
	cout << "| " << setw(12) << left << "Phone ";
	cout << "| " << setw(12) << left << "Balance ";
	cout << "\n________________________________________________________________________________________________\n\n";

	if (vClient.size() == 0)
		cout << "\t\t\t\tNo Clients Added in the System!\n";
	else
	{
		for (stClient c : vClient)
		{
			PrintClientLine(c);
		}
	}
	cout << "________________________________________________________________________________________________\n\n";
}

enMainMenuOptions ReadMainMenuOption()
{
	short Choice = 0;

	do
	{
		cout << "Choose what do you want to do? [1 to 8]? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 8);
	return (enMainMenuOptions)Choice;
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to main menu...";
	system("pause>0");
	PrintMainMenuScreen();
}

void AddDataToFile(vector<stClient> vClient)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	string Line = "";

	if (MyFile.is_open())
	{
		for (stClient c : vClient)
		{
			if (!c.MarkForDelete)
			{
				Line = ConvertRecordToLine(c);
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}

stClient ReadClient(vector<stClient> vClient)
{
	stClient Client;

	cout << "Adding New Client:\n\n";
	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);

	for (stClient c : vClient)
	{
		while (c.AccountNumber == Client.AccountNumber)
		{
			cout << "Client with [" << Client.AccountNumber << "] already exists, " << "Enter another account number? ";
			getline(cin >> ws, Client.AccountNumber);
		}
	}
	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

void AddClients()
{
	vector<stClient> vClient = LoadDataFromFile();
	stClient Client;
	char AddMore = 'n';

	cout << "\n--------------------------------------\n";
	cout << "\tAdd New Clients Screen";
	cout << "\n--------------------------------------\n";
	do
	{
		Client = ReadClient(vClient);
		vClient.push_back(Client);
		AddDataToFile(vClient);
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;
	} while (tolower(AddMore == 'y'));

}

void PrintClientInfoCard(stClient Client)
{
	cout << "\n--------------------------------------\n";
	cout << "Account Number: " << Client.AccountNumber;
	cout << "\nPin Code    : " << Client.PinCode;
	cout << "\nName        : " << Client.Name;
	cout << "\nPhone       : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n--------------------------------------\n";
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vClient)
{
	for (stClient& c : vClient)
	{
		if (c.AccountNumber == AccountNumber)
		{
			c.MarkForDelete = 1;
			return true;
		}
	}
	return false;
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> vClient)
{
	for (stClient& c : vClient)
	{
		if (c.AccountNumber == AccountNumber)
		{
			return true;
		}
	}
	return false;
}

void DeleteClients()
{
	vector<stClient> vClient = LoadDataFromFile();
	string AccountNum;
	char LastDecision = 'n';

	cout << "\n--------------------------------------\n";
	cout << "\tDelete Clients Screen";
	cout << "\n--------------------------------------\n\n";

	cout << "Enter Account Number? ";
	getline(cin >> ws, AccountNum);

	if (MarkClientForDeleteByAccountNumber(AccountNum, vClient))
	{
		for (stClient c : vClient)
		{
			if (c.MarkForDelete)
			{
				cout << "\nThe following are the client details: ";
				PrintClientInfoCard(c);
				cout << "\nAre you sure you want to delete this client? y/n? ";
				cin >> LastDecision;
				if (tolower(LastDecision) == 'y')
				{
					AddDataToFile(vClient);
					cout << "\nClient Deleted Successfuly.\n";
					break;
				}
				else
					break;
			}
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNum << ") is Not Found!\n";
	}
}

stClient UpdateClient(stClient Client)
{
	cout << "Enter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

void UpdateClientInfo()
{
	vector<stClient> vClient = LoadDataFromFile();
	stClient Client;
	char LastDecision = 'n';

	cout << "\n--------------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n--------------------------------------\n\n";
	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);
	if (FindClientByAccountNumber(Client.AccountNumber, vClient))
	{
		for (stClient& c : vClient)
		{
			if (c.AccountNumber == Client.AccountNumber)
			{
				cout << "\nThe following are the client details: ";
				PrintClientInfoCard(c);
				cout << "\nAre you sure you want to update this client? y/n? ";
				cin >> LastDecision;
				if (tolower(LastDecision) == 'y')
				{
					c = UpdateClient(c);
					AddDataToFile(vClient);
					cout << "\nClient updated Successfuly.\n";
					break;
				}
				else
					break;
			}
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << Client.AccountNumber << ") is Not Found!\n";
	}
}

void FindUser()
{
	vector<stClient> vClient = LoadDataFromFile();
	stClient Client;
	char LastDecision = 'n';

	cout << "\n--------------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n--------------------------------------\n\n";
	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);
	if (FindClientByAccountNumber(Client.AccountNumber, vClient))
	{
		for (stClient& c : vClient)
		{
			if (c.AccountNumber == Client.AccountNumber)
			{
				cout << "\nThe following are the client details: ";
				PrintClientInfoCard(c);
			}
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << Client.AccountNumber << ") is Not Found!\n";
	}
}

enTransactionsMenuOptions ReadTransactionsMenuOptions()
{
	short Choice = 0;

	do
	{
		cout << "Choose what do you want to do? [1 to 4]? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 4);
	return (enTransactionsMenuOptions)Choice;
}

void PrintTransactionsMenuScreen();

void GoBackToTransactionMenu()
{
	cout << "\n\nPress any key to go back to transaction menu...";
	system("pause>0");
	PrintTransactionsMenuScreen();
}

void Deposit()
{
	vector<stClient> vClient = LoadDataFromFile();
	string AccountNum;
	char LastDecision = 'n';
	int Amount = 0;

	cout << "\n----------------------------------------------\n";
	cout << "\t\tDeposit Screen";
	cout << "\n----------------------------------------------\n\n";
	cout << "Enter Account Number? ";
	getline(cin >> ws, AccountNum);
	if (FindClientByAccountNumber(AccountNum, vClient))
	{
		for (stClient& c : vClient)
		{
			if (c.AccountNumber == AccountNum)
			{
				cout << "\nThe following are the client details: ";
				PrintClientInfoCard(c);
				cout << "\nPlease enter deposit amount? ";
				cin >> Amount;
				cout << "\nAre you sure you want to perform this transactions? y/n? ";
				cin >> LastDecision;
				if (LastDecision == 'y')
				{
					c.AccountBalance += Amount;
					AddDataToFile(vClient);
					cout << "\nAmount added successfully!\n";
					break;
				}
				else
					break;
			}
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNum << ") is Not Found!\n";
	}
}

void Withdraw()
{
	vector<stClient> vClient = LoadDataFromFile();
	string AccountNum;
	char LastDecision = 'n';
	double Amount = 0;

	cout << "\n----------------------------------------------\n";
	cout << "\t\tWithdraw Screen";
	cout << "\n----------------------------------------------\n\n";
	cout << "Enter Account Number? ";
	getline(cin >> ws, AccountNum);
	if (FindClientByAccountNumber(AccountNum, vClient))
	{
		for (stClient& c : vClient)
		{
			if (c.AccountNumber == AccountNum)
			{
				cout << "\nThe following are the client details: ";
				PrintClientInfoCard(c);
				cout << "\nPlease enter withdraw amount? ";
				cin >> Amount;
				while (Amount > c.AccountBalance)
				{
					cout << "\nAmount Exceeds the balance, you can withdraw uo to: " << c.AccountBalance;
					cout << "\nPlease enter withdraw amount? ";
					cin >> Amount;
				}
				cout << "\nAre you sure you want to perform this transactions? y/n? ";
				cin >> LastDecision;
				if (LastDecision == 'y')
				{
					c.AccountBalance -= Amount;
					AddDataToFile(vClient);
					cout << "\nwithdraw added successfully!\n";
					break;
				}
				else
					break;
			}
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNum << ") is Not Found!\n";
	}
}

void TotalBalances()
{
	vector<stClient> vClient = LoadDataFromFile();
	double TotalAmount = 0;
	cout << "\n\t\t\t\tClient List (" << vClient.size() << ") Client(s).\n";
	cout << "________________________________________________________________________________________________\n\n";
	cout << "| " << setw(15) << left << "Account Number ";
	cout << "| " << setw(40) << left << "Client Name ";
	cout << "| " << setw(12) << left << "Balance ";
	cout << "\n________________________________________________________________________________________________\n\n";

	if (vClient.size() == 0)
		cout << "\t\t\t\tNo Clients Added in the System!\n";
	else
	{
		for (stClient c : vClient)
		{
			PrintClientLine(c);
			TotalAmount += c.AccountBalance;
		}
	}
	cout << "________________________________________________________________________________________________\n\n";
	cout << "\t\t\t\t Total Balances = " << TotalAmount;
}

void PerformTransactionsMenuOptions(enTransactionsMenuOptions TransactionsMenuOptions)
{
	switch (TransactionsMenuOptions)
	{
	case enTransactionsMenuOptions::eDeposit:
		system("cls");
		Deposit();
		GoBackToTransactionMenu();
		break;
	case enTransactionsMenuOptions::eWithdraw:
		system("cls");
		Withdraw();
		GoBackToTransactionMenu();
		break;
	case enTransactionsMenuOptions::eTotalBalances:
		system("cls");
		TotalBalances();
		GoBackToTransactionMenu();
		break;
	case enTransactionsMenuOptions::eMainMenu:
		system("cls");
		PrintMainMenuScreen();
		break;
	}
}

void PrintTransactionsMenuScreen()
{
	system("cls");
	cout << "==========================================================\n";
	cout << "\t\t Transactions Menu Screen\n";
	cout << "==========================================================\n";
	cout << "\t [1] Deposit.\n";
	cout << "\t [2] Withdraw.\n";
	cout << "\t [3] Total Balances.\n";
	cout << "\t [4] Main Menu.\n";
	cout << "==========================================================\n";
	PerformTransactionsMenuOptions(ReadTransactionsMenuOptions());
}

void LoginScreen();

void GoBackToManageUsersScreen()
{
	cout << "\n\nPress any key to go back to manage users menu...";
	system("pause>0");
	PrintManageUsersMenuScreen();
}

enManageUsersMenuOptions ReadManageUsersMenuOptions()
{
	short Choice = 0;

	cout << "Choose what do you want to do? [1 to 6]? ";
	cin >> Choice;
	return (enManageUsersMenuOptions)Choice;
}

void PrintUserLine(stLogin Login)
{
	cout << "| " << setw(20) << left << Login.Username;
	cout << "| " << setw(15) << left << Login.Password;
	cout << "| " << setw(15) << left << Login.Permissions;
	cout << endl;
}

void ShowUsersList()
{
	vector<stLogin> vLogin = LoadLoginAccountsFromFile();
	cout << "\n\t\t\t\tUsers List (" << vLogin.size() << ") User(s).\n";
	cout << "________________________________________________________________________________________________\n\n";
	cout << "| " << setw(20) << left << "User Name ";
	cout << "| " << setw(15) << left << "Password ";
	cout << "| " << setw(15) << left << "Permissions";
	cout << "\n________________________________________________________________________________________________\n\n";

	if (vLogin.size() == 0)
		cout << "\t\t\t\tNo Users Added in the System!\n";
	else
	{
		for (stLogin l : vLogin)
		{
			PrintUserLine(l);
		}
	}
	cout << "________________________________________________________________________________________________\n\n";
}

void FillUserAccess(stManageUsersAccess& sManageUsersAccess)
{
	cout << "\nDo you want to give access to:\n";

	cout << "\nShow Client List? y/n? ";
	cin >> sManageUsersAccess.stListClient;
	cout << "\nAdd New Client? y/n? ";
	cin >> sManageUsersAccess.stAddNewClient;
	cout << "\nDelete Client? y/n? ";
	cin >> sManageUsersAccess.stDeleteClient;
	cout << "\nUpdate Client? y/n? ";
	cin >> sManageUsersAccess.stUpdateClient;
	cout << "\nFind Client? y/n? ";
	cin >> sManageUsersAccess.stFindClient;
	cout << "\nTransactions? y/n? ";
	cin >> sManageUsersAccess.stTransactions;
	cout << "\nManage Users? y/n? ";
	cin >> sManageUsersAccess.stManageUsers;
}

void AddDataToFile2(vector<stLogin> vLogin)
{
	fstream MyFile;
	MyFile.open(FileName2, ios::out);
	string Line = "";

	if (MyFile.is_open())
	{
		for (stLogin& l : vLogin)
		{
			if (!l.MarkForDelete)
			{
				Line = ConvertRecordToLine2(l);
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}

int ReadUserPermission()
{
	stManageUsersAccess sManageUsersAccess;
	int UserPermission = 0;
	cout << "\nDo you want to give full access? y/n? ";
	cin >> sManageUsersAccess.GiveFullAccess;

	if (tolower(sManageUsersAccess.GiveFullAccess) == 'y')
	{
		UserPermission = -1;
		return UserPermission;
	}
	else
	{
		FillUserAccess(sManageUsersAccess);
		if (tolower(sManageUsersAccess.stListClient) == 'y')
			UserPermission += (int)eManageUsersAccess::eeListClient;
		if (tolower(sManageUsersAccess.stAddNewClient) == 'y')
			UserPermission += (int)eManageUsersAccess::eeAddNewClient;
		if (tolower(sManageUsersAccess.stDeleteClient) == 'y')
			UserPermission += (int)eManageUsersAccess::eeDeleteClient;
		if (tolower(sManageUsersAccess.stUpdateClient) == 'y')
			UserPermission += (int)eManageUsersAccess::eeUpdateClient;
		if (tolower(sManageUsersAccess.stFindClient) == 'y')
			UserPermission += (int)eManageUsersAccess::eeFindClient;
		if (tolower(sManageUsersAccess.stTransactions) == 'y')
			UserPermission += (int)eManageUsersAccess::eeTransactions;
		if (tolower(sManageUsersAccess.stManageUsers) == 'y')
			UserPermission += (int)eManageUsersAccess::eeManageUsers;
	}
	return UserPermission;
}

bool FindUserByUsername(string username, vector<stLogin> vLogin)
{
	for (stLogin& l : vLogin)
	{
		if (l.Username == username)
		{
			return true;
		}
	}
	return false;
}

void AddNewUsers()
{
	vector<stLogin> vLogin = LoadLoginAccountsFromFile();
	stLogin Login;
	char AddMore = 'n';

	cout << "\n----------------------------------------------\n";
	cout << "\t\tAdd New User Screen";
	cout << "\n----------------------------------------------\n";
	cout << "Adding New User:\n\n";

	do
	{
		cout << "Enter Username? ";
		getline(cin >> ws, Login.Username);

		while (FindUserByUsername(Login.Username, vLogin))
		{
			cin.clear();
			cout << "\nUser with [" << Login.Username << "] already exists, Enter another Username? ";
			getline(cin >> ws, Login.Username);
		}
		cout << "Enter Password? ";
		getline(cin >> ws, Login.Password);
		Login.Permissions = ReadUserPermission();
		vLogin.push_back(Login);
		AddDataToFile2(vLogin);
		cout << "\nUser Added Successfully, do you want to add more Users? y/n? ";
		cin >> AddMore;
	} while (tolower(AddMore) == 'y');
}

bool MarkUserForDeleteByUsername(string username, vector<stLogin>& vLogin)
{
	for (stLogin& l : vLogin)
	{
		if (l.Username == username)
		{
			l.MarkForDelete = 1;
			return true;
		}
	}
	return false;
}

void PrintUserInfoCard(stLogin Login)
{
	cout << "\n--------------------------------------\n";
	cout << "Username   : " << Login.Username;
	cout << "\nPassword   : " << Login.Password;
	cout << "\nPermissions: " << Login.Permissions;
	cout << "\n--------------------------------------\n";
}

void DeleteUsers()
{
	vector<stLogin> vLogin = LoadLoginAccountsFromFile();
	string Username;
	char LastDecision = 'n';

	cout << "\n--------------------------------------\n";
	cout << "\tDelete Users Screen";
	cout << "\n--------------------------------------\n\n";

	cout << "Please enter username? ";
	getline(cin >> ws, Username);

	if (MarkUserForDeleteByUsername(Username, vLogin))
	{
		for (stLogin& l : vLogin)
		{
			if (l.MarkForDelete)
			{
				cout << "\nThe following are the user details: ";
				PrintUserInfoCard(l);
				cout << "\nAre you sure you want to delete this user? y/n? ";
				cin >> LastDecision;
				if (tolower(LastDecision) == 'y')
				{
					AddDataToFile2(vLogin);
					cout << "\nUser Deleted Successfuly.\n";
					break;
				}
				else
					break;
			}
		}
	}
	else
	{
		cout << "\nUser with username (" << Username << ") is Not Found!\n";
	}
}

stLogin UpdateUser(stLogin Login)
{
	cout << "Enter Password? ";
	getline(cin >> ws, Login.Password);
	cout << "Enter Permissions? ";
	Login.Permissions = ReadUserPermission();
	return Login;
}

void UpdateUserInfo()
{
	vector<stLogin> vLogin = LoadLoginAccountsFromFile();
	stLogin Login;
	char LastDecision = 'n';

	cout << "\n--------------------------------------\n";
	cout << "\tUpdate Users Screen";
	cout << "\n--------------------------------------\n\n";
	cout << "Please enter Username ? ";
	getline(cin >> ws, Login.Username);
	if (FindUserByUsername(Login.Username, vLogin))
	{
		for (stLogin& l : vLogin)
		{
			if (l.Username == Login.Username)
			{
				cout << "\nThe following are the user details: ";
				PrintUserInfoCard(l);
				cout << "\nAre you sure you want to update this user? y/n? ";
				cin >> LastDecision;
				if (tolower(LastDecision) == 'y')
				{
					l = UpdateUser(l);
					AddDataToFile2(vLogin);
					cout << "\nUser updated Successfuly.\n";
					break;
				}
				else
					break;
			}
		}
	}
	else
	{
		cout << "\nUser with username (" << Login.Username << ") is Not Found!\n";
	}
}

void SearchUser()
{
	vector<stLogin> vLogin = LoadLoginAccountsFromFile();
	stLogin Login;
	char LastDecision = 'n';

	cout << "\n--------------------------------------\n";
	cout << "\tFind User Screen";
	cout << "\n--------------------------------------\n\n";
	cout << "Please enter Username? ";
	getline(cin >> ws, Login.Username);
	if (FindUserByUsername(Login.Username, vLogin))
	{
		for (stLogin& l : vLogin)
		{
			if (l.Username == Login.Username)
			{
				cout << "\nThe following are the cluserient details: ";
				PrintUserInfoCard(l);
			}
		}
	}
	else
	{
		cout << "\nUser with username (" << Login.Username << ") is Not Found!\n";
	}
}

void PerformManageUsersMenuOptions(enManageUsersMenuOptions ManageUsersMenuOptions)
{
	switch (ManageUsersMenuOptions)
	{
	case enManageUsersMenuOptions::eListUsers:
		system("cls");
		ShowUsersList();
		GoBackToManageUsersScreen();
		break;
	case enManageUsersMenuOptions::eAddNewUser:
		system("cls");
		AddNewUsers();
		GoBackToManageUsersScreen();
		break;
	case enManageUsersMenuOptions::eDeleteUser:
		system("cls");
		DeleteUsers();
		GoBackToManageUsersScreen();
		break;
	case enManageUsersMenuOptions::eUpdateUser:
		system("cls");
		UpdateUserInfo();
		GoBackToManageUsersScreen();
		break;
	case enManageUsersMenuOptions::eFindUser:
		system("cls");
		SearchUser();
		GoBackToManageUsersScreen();
		break;
	case enManageUsersMenuOptions::MainMenu:
		PrintMainMenuScreen();
		break;
	}
}

void PrintManageUsersMenuScreen()
{
	system("cls");
	cout << "==========================================================\n";
	cout << "\t\t Manage Users Menu Screen\n";
	cout << "==========================================================\n";
	cout << "\t [1] List Users.\n";
	cout << "\t [2] Add New User.\n";
	cout << "\t [3] Delete User.\n";
	cout << "\t [4] Update User.\n";
	cout << "\t [5] Find User.\n";
	cout << "\t [6] Main Menu.\n";
	cout << "==========================================================\n";
	PerformManageUsersMenuOptions(ReadManageUsersMenuOptions());
}

void AccessDenied()
{
	cout << "\n---------------------------------------\n";
	cout << "Access Denied,\n";
	cout << "You don't Have Permission To Do this,\n";
	cout << "Please Contact Your Admin.";
	cout << "\n_______________________________________\n\n";
}

bool CheckAccessPermission(eManageUsersAccess Permission)
{
	if (CurrentUser.Permissions == -1)
		return true;

	if ((CurrentUser.Permissions & Permission) == Permission)
		return true;
	else
		return false;
}

void PerformMainMenuOptions(enMainMenuOptions MainMenuOptions)
{
	switch (MainMenuOptions)
	{
	case enMainMenuOptions::DisplayClientList:
		if (!CheckAccessPermission(eManageUsersAccess::eeListClient))
		{
			system("cls");
			AccessDenied();
		}
		else
		{
			system("cls");
			ShowClientList();
		}
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::AddNewClients:
		if (!CheckAccessPermission(eManageUsersAccess::eeAddNewClient))
		{
			system("cls");
			AccessDenied();
		}
		else
		{
			system("cls");
			AddClients();
		}
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::DeleteClient:
		if (!CheckAccessPermission(eManageUsersAccess::eeDeleteClient))
		{
			system("cls");
			AccessDenied();
		}
		else
		{
			system("cls");
			DeleteClients();
		}
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eUpdateClientInfo:
		if (!CheckAccessPermission(eManageUsersAccess::eeUpdateClient))
		{
			system("cls");
			AccessDenied();
		}
		else
		{
			system("cls");
			UpdateClientInfo();
		}
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eFindClient:
		if (!CheckAccessPermission(eManageUsersAccess::eeFindClient))
		{
			system("cls");
			AccessDenied();
		}
		else
		{
			system("cls");
			FindUser();
		}
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eTransactions:
		if (!CheckAccessPermission(eManageUsersAccess::eeTransactions))
		{
			system("cls");
			AccessDenied();
			GoBackToMainMenu();
		}
		else
		{
			system("cls");
			PrintTransactionsMenuScreen();
		}
		break;

	case enMainMenuOptions::eManageUsers:
		if (!CheckAccessPermission(eManageUsersAccess::eeManageUsers))
		{
			system("cls");
			AccessDenied();
			GoBackToMainMenu();
		}
		else
		{
			system("cls");
			PrintManageUsersMenuScreen();
		}
		break;

	case enMainMenuOptions::eLogout:
		system("cls");
		LoginScreen();
		break;
	}
}

void PrintMainMenuScreen()
{
	system("cls");
	cout << "=================================================\n";
	cout << "\t\t Main Menu Screen\n";
	cout << "=================================================\n";
	cout << "\t [1] Show Client List.\n";
	cout << "\t [2] Add New Client.\n";
	cout << "\t [3] Delete Client.\n";
	cout << "\t [4] Update Client Info.\n";
	cout << "\t [5] Find Client.\n";
	cout << "\t [6] Transactions.\n";
	cout << "\t [7] Manage Users.\n";
	cout << "\t [8] Logout.\n";
	cout << "=================================================\n";
	PerformMainMenuOptions(ReadMainMenuOption());
}

vector<stLogin> LoadLoginAccountsFromFile()
{
	fstream MyFile;
	MyFile.open(FileName2, ios::in);
	vector<stLogin> vLogin;
	string Line = "";
	stLogin Login;

	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			Login = ConvertLineToRecord2(Line);
			vLogin.push_back(Login);
		}
		MyFile.close();
	}
	return vLogin;
}

stLogin ReadInputLogin()
{
	stLogin InputLogin;

	cout << "Enter Username? ";
	getline(cin >> ws, InputLogin.Username);
	cout << "Enter Password? ";
	getline(cin >> ws, InputLogin.Password);
	return InputLogin;
}

bool IsLoginCorrect(stLogin InputLogin, vector<stLogin> vLogin, stLogin& MatchedUser)
{
	for (stLogin l : vLogin)
	{
		if ((l.Username == InputLogin.Username) && (l.Password == InputLogin.Password))
		{
			MatchedUser = l;
			return true;
		}
	}
	return false;
}

void LoginScreen()
{
	vector<stLogin> vLogin = LoadLoginAccountsFromFile();
	stLogin InputLogin;
	bool FirstTry = true;
	stLogin MatchedUser;

	while (true)
	{
		system("cls");
		cout << "\n----------------------------------------------\n";
		cout << "\t\tLogin Screen";
		cout << "\n----------------------------------------------\n";
		if (!FirstTry)
			cout << "Invalid Username/Password!\n";
		InputLogin = ReadInputLogin();
		if (IsLoginCorrect(InputLogin, vLogin, MatchedUser))
			break;
		FirstTry = false;
	}
	CurrentUser = MatchedUser;
	PrintMainMenuScreen();
}

int main()
{
	LoginScreen();

	system("pause>0");
	return 0;
}