#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

class account
{
	int acno;
	char name[50];
	int deposit;
	char type;

public:
	void create_account();
	void show_account() const;
	void dep(int);
	int retacno() const;
};
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void account::create_account()
{
	cout << "\nEnter The account No. :";
	cin >> acno;
	cout << "\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nEnter Type of The account (C/S) : ";
	cin >> type;
	type = toupper(type);
	cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin >> deposit;
	cout << "\n\n\nAccount Created..";
}
void account::show_account() const
{
	cout << "\nAccount No. : " << acno;
	cout << "\nAccount Holder Name : " << name;
	cout << "\nType of Account : " << type;
	cout << "\nBalance amount : " << deposit;
}
void account::dep(int x)
{
	deposit += x;
}
int account::retacno() const
{
	return acno;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void write_account();
void deposit_withdraw(int n, int option);
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
int main()
{
	char ch;
	int num;
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. NEW ACCOUNT";
		cout << "\n\n\t02. DEPOSIT AMOUNT";
		cout << "\n\n\t03. WITHDRAW AMOUNT";
		cout << "\n\n\t04. BALANCE ENQUIRY";
		cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout << "\n\n\t06. CLOSE AN ACCOUNT";
		cout << "\n\n\t07. MODIFY AN ACCOUNT";
		cout << "\n\n\t08. EXIT";
		cout << "\n\n\tSelect Your Option (1-8) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout << "\n\n\tEnter The account No. : ";
			cin >> num;
			deposit_withdraw(num, 1);
			break;

		default:
			cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (ch != '8');
	return 0;
}

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
	outFile.close();
}
void deposit_withdraw(int n, int option)
{
	int amt;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	File.read(reinterpret_cast<char *>(&ac), sizeof(account));
	if (ac.retacno() == n)
	{

		ac.show_account();
		cout << "\n\n\tTO DEPOSITE AMOUNT ";
		cout << "\n\nEnter The amount to be deposited";
		cin >> amt;
		ac.dep(amt);
	}
	int pos = (-1) * static_cast<int>(sizeof(ac));
	File.seekp(pos, ios::cur);
	File.write(reinterpret_cast<char *>(&ac), sizeof(account));
	cout << "\n\n\t Record Updated";
}