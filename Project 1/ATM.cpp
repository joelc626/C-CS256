//Joel Castro
//CS 256
//Project 1 Task 3: ATM Software

//This program is similar to the ones used in ATM machines.
//The program is to handle a person's savings and checking accounts
//and should handle services like transfers, withdraws and displaying
//account balances.

#include<iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
using namespace std;

//Asks the user how much money to transfer from Checking to Savings
void chetosav(double &s, double &c)
{
	double amount;

	//Ask for amount
	cout << "Transfer amount from Checking account: $";
	cin >> amount;

	//If asking to transfer more than available, display error
	if (amount > c)
	{
		cout << "Transaction not completed, only $" << setprecision(2)
			<< fixed << c << " in Checking account\n";
		system("pause");
		return;
	}
	//If valid request, then subtract and add to the accounts
	else
	{
		s += amount;
		c -= amount;
	}
	return;
}

//Asks the user how much money to transfer from Savings to Checking
void savtoche(double &s, double &c)
{
	double amount;

	//Ask for amount
	cout << "Transfer amount from Savings account: $";
	cin >> amount;

	//If asking to transfer more than available, display error
	if (amount > s)
	{
		cout << "Transaction not completed, only $" << setprecision(2)
			<< fixed << s << " in Savings account\n";
		system("pause");
		return;
	}
	//If valid request, then subtract and add to the accounts
	else
	{
		s -= amount;
		c += amount;
	}
	return;
} 

//Asks the user how much money to withdraw from Savings or Checking account
void withdraw(double &s, double &c)
{
	int option;
	double amount;

	//Ask what account to withdraw from
	do
	{
		cout << "\nWould you like to withdraw from: \n"
			<< "(1) Savings account\n"
			<< "(2) Checking account\n";
		cin >> option;
		
		//If a string or character is entered, redisplay the options
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			option = 0;
		}
	}
	while (option != 1 && option != 2);

	//If 1 is entered then subtract from Savings
	if (option == 1)
	{
		cout << "Withdraw amount from Savings: $";
		cin >> amount;

		//If asking to withdraw more than available, display error
		if (amount > s)
		{
			cout << "Transaction not completed, only $" << setprecision(2)
					<< fixed << s << " in Savings account\n";
			system("pause");
			return;
		}
		s -= amount;
	}
	//If 2 is entered then subtract from Checkings
	else
	{
		cout << "Withdraw amount from Checking: $";
		cin >> amount;

		//If asking to withdraw more than available, display error
		if (amount > c)
		{
			cout << "Transaction not completed, only $" << setprecision(2)
					<< fixed << c << " in Checking account\n";
			system("pause");
			return;
		}
		c -= amount;
	}
}

int main()
{
	int pin, option;
	int tries = 1;
	double sav = 1000.0;
	double che = 1000.0;

	//Ask the user to type in his/her PIN
	do
	{
		//After three tries, display error and end the program
		if (tries > 3)
		{
			cout << "Too many illegal PINs. Try later again.\n";
			return 0;
		}
		system("cls");
		cout << "*** Welcome to Cal Poly's ATM ****\n";
		cout << "Please enter your PIN: ";
		cin >> pin;
		
		//If a string or character is entered, redisplay the options
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			pin = 0;
		}
		tries++;
	}
	while(pin != 111);
	
	//This do while is until the user decides to quit the program
	do
	{
		//Asks the user what they would like to do with their accounts
		do
		{
			system("cls");
			cout << "*** Welcome To Cal Poly's ATM System ***\n\n"
				<< "(1) Transfer from checking account to savings account\n"
				<< "(2) Transfer from savings account to checking account\n"
				<< "(3) Savings account balance\n"
				<< "(4) Checking account balance\n"
				<< "(5) Withdraw Cash from either account\n"
				<< "(6) Exit\n"
				<< "==> Please select option (1-6): ";
			cin >> option;

			//If a string or character is entered, redisplay the options
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				option = 0;
			}
		}
		while (option < 1 || option > 6);

		//Once the user selects a valid option then execute appropriate code
		switch(option)
		{
			case 1:
				chetosav(sav, che);
				break;
			case 2:
				savtoche(sav, che);
				break;
			case 3:
				cout << "Savings account balance is: $" << setprecision(2)
					<< fixed << sav << "\n";
				system("pause");
				break;
			case 4:
				cout << "Checking account balance is: $" << setprecision(2)
					<< fixed << che << "\n";
				system("pause");
				break;
			case 5:
				withdraw(sav, che);
				break;
			default:
				cout <<"\nThank you for using the ATM system.\n";
		}
	}
	while (option !=6);

	system("pause");
	return 0;
}