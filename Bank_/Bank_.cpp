#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const string FileName = "Clients.txt";


struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};
enum enMainMenueOptions
{
	enShowListClients = 1, enAddingNewClient = 2,
	enDeleteClient = 3, enUpdateDataClient = 4,
	enFindClientInfo = 5, enTransaction = 6,enExitProgram = 7
};
enum enTransactions {
	enDeposit = 1, enWithdraw = 2,
	enTotalBalances = 3, MainMenue = 4
};
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; 
	
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
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

sClient ConvertLinetoRecord(string Line, string Seperator ="#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//cast double to string 
	
		return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator ="#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}
bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			if (Client.AccountNumber == AccountNumber)
			{
				MyFile.close();
				return true;
			}
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return false;
}
sClient ReadNewClient()
{
	sClient Client;
	cout << "Enter Account Number? ";
	
	getline(cin >> ws, Client.AccountNumber);//  whitespace character
	while (ClientExistsByAccountNumber(Client.AccountNumber,FileName))
	{
		cout << "\nClient with [" << Client.AccountNumber << "]already exists, Enter another Account Number ? ";
		getline(cin >> ws, Client.AccountNumber);
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
vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}
void PrintClientRecordLine(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
	vector <sClient> vClients;
	vClients=LoadCleintsDataFromFile(FileName);
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
		cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else
		for (sClient Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n-----------------------------------\n";
}
bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
{
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}
sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;
	Client.AccountNumber = AccountNumber;
	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber,vector <sClient>&vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}
vector <sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//over write
	string DataLine;
	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				
				
					DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}
void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(FileName,ConvertRecordToLine(Client));
}
void AddNewClients()
{
	char AddMore = 'Y';
	do
	{
		cout << "Adding New Client:\n\n";
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
			cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>&vClients)
{
	sClient Client;
	char Answer = 'Y';
	if (FindClientByAccountNumber(AccountNumber, vClients,Client))
	{
		PrintClientCard(Client);
		cout << "\n\nAre you sure you want delete this client? y/n? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y');
		{
			MarkClientForDeleteByAccountNumber(AccountNumber,vClients);
			SaveCleintsDataToFile(FileName, vClients);
			vClients = LoadCleintsDataFromFile(FileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber<< ") is Not Found!";
		return false;
	}
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients,Client))
	{
			PrintClientCard(Client);
		cout << "\n\nAre you sure you want update this client? y/n ? ";
			cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveCleintsDataToFile(FileName, vClients);
			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}
string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}

void ShowDeleteClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n-----------------------------------\n";
	vector <sClient> vClients =LoadCleintsDataFromFile(FileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
}
void ShowUpdateClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-----------------------------------\n";
	vector <sClient> vClients =LoadCleintsDataFromFile(FileName);
	string AccountNumber = ReadClientAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}
void ShowAddNewClientsScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tAdd New Clients Screen";
	cout << "\n-----------------------------------\n";
	AddNewClients();
}

void ShowFindClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n-----------------------------------\n";
	vector <sClient> vClients =LoadCleintsDataFromFile(FileName);
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	if (FindClientByAccountNumber(AccountNumber, vClients,Client))
		PrintClientCard(Client);
	else
		cout << "\nClient with Account Number[" << AccountNumber<< "] is not found!";
}
void ShowEndScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tProgram Ends :-)";
	cout << "\n-----------------------------------\n";
}


short ReadMainMenueOption()
{	
	short Choice = 0;
	do {
		cout << "Choose what do you want to do? [1 to 7]? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 7);
	return Choice;
}
void ShowMainMenue(); // Function declaration 
void ShowTransactionsMenue();// Function declaration
void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenue();
}
short ReadTransactionsMenue() {
	short choose = 0;
	do
	{
		cout << "Choose What do You Want To Do ? [1 to 4]?";
		cin >> choose;

	} while (choose < 1 || choose > 4);
	return choose;
}
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient>& Vclient) {


	char Asksour = 'y';
	cout << "\n\n Are You sure you want perfrom this Transaction ? Y/N?";
	cin >> Asksour;
	if (tolower(Asksour) == 'y') {
		for (sClient& client : Vclient) {
			if (client.AccountNumber == AccountNumber) {
				client.AccountBalance += Amount;
				SaveCleintsDataToFile(FileName, Vclient);
				cout << "\n\nDone Successfully.New balance is = " << client.AccountBalance;
				 return true;
			}
		}
		return false;
	}

}



void GoBacktransactionMenue() {
	cout << "\n\n Press Any Key To Go Back To Transactions Menue...";
	system("pause>0");
	ShowTransactionsMenue();
}


void ShowDeposit_screen() {
	cout << "\n-----------------------------------\n";
	cout << "\tDeposit Screen";
	cout << "\n-----------------------------------\n";
	sClient Client;

	vector <sClient> vClients =LoadCleintsDataFromFile(FileName);

	string AccountNumber = ReadClientAccountNumber();

	while (!FindClientByAccountNumber(AccountNumber, vClients,Client))
	{
		cout << "\nClient with [" << AccountNumber << "] does notexist.\n";
			AccountNumber = ReadClientAccountNumber();
	}
	PrintClientCard(Client);
	double Amount = 0;
	cout << "\nPlease Enter Deposit Amount? ";
	cin >> Amount;
	DepositBalanceToClientByAccountNumber(AccountNumber, Amount,vClients);
}
void showWithDrawScreen() {
	
		cout << "\n-----------------------------------\n";
		cout << "\tWithdraw Screen";
		cout << "\n-----------------------------------\n";
		sClient Client;
		vector <sClient> vClients =LoadCleintsDataFromFile(FileName);
		string AccountNumber = ReadClientAccountNumber();
		while (!FindClientByAccountNumber(AccountNumber, vClients,Client))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
				AccountNumber = ReadClientAccountNumber();
		}
		PrintClientCard(Client);

		double Amount = 0;
		cout << "\nPlease enter withdraw amount? ";
		cin >> Amount;
		
		while (Amount > Client.AccountBalance)//chack
		{
			cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
				cout << "Please enter another amount? ";
			cin >> Amount;
		}
		DepositBalanceToClientByAccountNumber(AccountNumber, Amount *-1, vClients);
	}
void PrintClientRecordBalanceLine(sClient DClient) {
	
	
		cout << "| " << setw(15) << left << DClient.AccountNumber;
		cout << "| " << setw(40) << left << DClient.Name;
		cout << "| " << setw(12) << left << DClient.AccountBalance;
	
}
void ShowTotalBalances() {
	
	
	vector <sClient> vClients =LoadCleintsDataFromFile(FileName);
		cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
			cout <<
			"\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout <<
			"\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		double TotalBalances = 0;
		if (vClients.size() == 0) {

			cout << "\t\t\t\tNo Clients Available In the System!";
		}
		else
			for (sClient Client : vClients)
			{
				PrintClientRecordBalanceLine(Client);
				TotalBalances += Client.AccountBalance;
				cout << endl;
			}
		cout <<
			"\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\t\t\t Total Balances = " << TotalBalances;
	}

void showTotalBalancesScreen() {

	ShowTotalBalances();

}
void PerfromTransactionsScreens(enTransactions TransactionsMenue) {
	switch (TransactionsMenue)
	{
	case enTransactions::enDeposit:
		system("cls");
		ShowDeposit_screen();
		GoBacktransactionMenue();
		break;
	case enTransactions::enWithdraw:
		system("cls");
		showWithDrawScreen();
		GoBacktransactionMenue();
		break;
	case enTransactions::enTotalBalances:
		system("cls");
		showTotalBalancesScreen();
		GoBacktransactionMenue();
		break;
	case enTransactions::MainMenue:
		system("cls");
		ShowMainMenue();
		break;
	}
}
void ShowTransactionsMenue() {
	system("cls");
	cout << "=================================================\n";
	cout << "\t  Transactions Menue Screen \n";
	cout << "=================================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances." << endl;
	cout << "\t[4] Main Menue."<<"\n";
	cout << "=================================================\n";
	PerfromTransactionsScreens(enTransactions(ReadTransactionsMenue()));
}


void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
	switch (MainMenueOption)
	{
	case enMainMenueOptions::enShowListClients:
	{
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMenueOptions::enAddingNewClient:
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::enDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::enUpdateDataClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::enFindClientInfo:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::enTransaction:
		system("cls");
		ShowTransactionsMenue();
		break;
	case enMainMenueOptions::enExitProgram:
		system("cls");
		ShowEndScreen();
		break;
	}
}

void ShowMainMenue()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tMain Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Exit.\n";
	cout << "===========================================\n";
	PerfromMainMenueOption(enMainMenueOptions(ReadMainMenueOption()));
}
int main()
{
	ShowMainMenue();

	cout << "..."<<endl;
	system("pause>0");
	return 0;
}