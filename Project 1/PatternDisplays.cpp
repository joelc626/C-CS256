//Joel Castro
//CS 256
//Project 1 Task 2: Pattern Displays

//This program asks the user for the number of lines of pattern wish to
//be displayed. Keeping the number that the user enters between 1 and 20.

#include<iostream>
#include <limits>
using namespace std;

int main()
{
	int num;

	//Ask the user for how many lines of pattern
	do
	{
		cout << "How many lines of pattern would you like to see (1-20)? ";
		cin >> num;

		//If a string or character is entered, redisplay the question
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			num = 0;
		}
	}
	while ((num < 1 || num > 20));

	cout << "Pattern A \t\tPattern B\n";
	cout << "_____________________________________________\n";

	//Display the pattern
	for (int rows = 1; rows <= num; rows++)
	{
		//Prints Pattern A
		for (int patA = 1; patA <= rows; patA++)
			cout << "+";
		
		//Correct number of tab depend on the row the program is printing on
		if (rows < 8)
			cout << "\t\t\t";
		else if (rows < 16)
			cout << "\t\t";
		else
			cout << "\t";

		//Print Pattern B
		for (int patB = num; patB >= rows; patB--)
			cout << "+";
		cout << "\n";
	}

	system("pause");
	return 0;
}