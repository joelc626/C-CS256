//Joel Castro
//CS 256
//Project 1 Task 1: Math Tutor

//This program asks the user to select an addition,
//subtraction, multiplication or division problem.

#include<iostream>
#include <ctime>
using namespace std;

//Display the options in the menu
int menu()
{
	int choice;

	//Ask the user what type of problem they would like
	cout << "Select a type of problem or choose to quit:\n\n";
	cout << " 1. Addition\n";
	cout << " 2. Subtraction\n";
	cout << " 3. Multiplication\n";
	cout << " 4. Division\n";
	cout << " 5. Quit the program\n\n";
	cin >> choice;

	//If a string or character is entered, reset choice
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		choice = 0;
	}

	//If user enters invalid option then display error and redisplay menu
	if (choice < 1 || choice > 5)
	{
		do
		{
			cout << "\nIncorrect choice, please select an option by enter "
			<< "a number between 1 and 5\n\n";
			cout << " 1. Addition\n";
			cout << " 2. Subtraction\n";
			cout << " 3. Multiplication\n";
			cout << " 4. Division\n";
			cout << " 5. Quit the program\n\n";
			cin >> choice;
			
			//If a string or character is entered, reset choice
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				choice = 0;
			}
		}
		while (choice < 1 || choice > 5);
	}
	return choice;
}

//Display a message if users answer is correct or incorrect
void check(int g, int c)
{
	if (g == c)
		cout << "Correct!\n\n";
	else
		cout << "Sorry, correct answer was " << c << ".\n\n";
}

int main()
{
	int choice, guess, corA;
	unsigned int num1, num2;

	//Get the system time
	unsigned seed = time(0);

	//Seed the random number generator
	srand(seed);
	
	cout << "Welcome to Math Tutor\n\n";

	//A do while loop to keep the menu diplaying until user decides to quit
	do
	{
		//Get valid choice of type of problem
		choice = menu();

		//Once the user selects a valid option then execute appropriate code
		switch(choice)
		{
		case 1:
			num1 = 1 + rand() % 1000;
			num2 = 1 + rand() % 1000;
			corA = num1 + num2;
			cout << "\n" << num1 << " + " << num2 << " = ";
			cin >> guess;
			check(guess, corA);
			break;
		case 2:
			do
			{
				num1 = 1 + rand() % 1000;
				num2 = 1 + rand() % 1000;
			}
			while (num1 < num2);
			corA = num1 - num2;
			cout << "\n" << num1 << " - " << num2 << " = ";
			cin >> guess;
			check(guess, corA);
			break;
		case 3:
			num1 = 1 + rand() % 100;
			num2 = 1 + rand() % 100;
			corA = num1 * num2;
			cout << "\n" << num1 << " * " << num2 << " = ";
			cin >> guess;
			check(guess, corA);
			break;
		case 4:
			do
			{
				num1 = 2 + rand() % 1000;
				num2 = 2 + rand() % 1000;
			}
			while ((num1 < num2) || (num1 % num2 != 0));
			corA = num1 / num2;
			cout << "\n" << num1 << " / " << num2 << " = ";
			cin >> guess;
			check(guess, corA);
			break;
		default:
			return 0;
		}
	}
	while (choice != 5);

	system("pause");
	return 0;
}