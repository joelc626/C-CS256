//Joel Castro
//CS 256
//Project 2 Task 2: Matrix Multiplication

//This program asks the user for two matrices and then ask what
//operation they which to be done with the two matrices.

#include<iostream>
#include <ctime>
using namespace std;

int menu();
bool addition(int, int, int, int);
bool subtraction(int, int, int, int);
bool multiplication(int, int, int, int);
bool transpose(int, int, int, int);

int main()
{
	int **x, **y, **z;
	int xRows, xCols, yRows, yCols, zRows, zCols;
	int choice = 0;
	
	//Get Rows and Columns of both matrices
	cout << "Enter number of rows matrix one: ";
	cin >> xRows;
	
	cout << "Enter number of columns for matrix one: ";
	cin >> xCols;

	cout << "Enter number of rows matrix two: ";
	cin >> yRows;

	cout << "Enter number of columns for matrix two: ";
	cin >> yCols;

	
	//Dynamic Memory Allocation for input array x and y 
	x = new int *[xRows];
	for(int i = 0; i < xRows; i++)
		*(x + i) = new int[xCols];

	y = new int *[yRows];
	for(int i = 0; i < yRows; i++)
		*(y + i) = new int[yCols];


	//Get input for matrix one
	for(int i = 0; i < xRows; i++)
		for(int j = 0; j < xCols; j++) {
			cout << "Enter element (" << i << ", " << j << ") for matrix one: ";
			cin >> *(*(x + i) + j);
		}

	//Get input for matrix two
	for(int i = 0; i < yRows; i++)
		for(int j = 0; j < yCols; j++) {
			cout << "Enter element (" << i << ", " << j << ") for matrix two: ";
			cin >> *(*(y + i) + j);
		}
	
	cout << "\nYour matrices:\n";

	//Print matirx x
	cout << "\nMatrix one: " << endl;
	for(int i = 0; i < xRows; i++) {
		for(int j = 0; j < xCols; j++)
			cout << *(*(x + i) + j) << "\t";
		cout << endl;
	}
	
	//Print matirx y
	cout << "\nMatrix two: " << endl;
	for(int i = 0; i < yRows; i++) {
		for(int j = 0; j < yCols; j++)
			cout << *(*(y + i) + j) << "\t";
		cout << endl;
	}

	//Assign appropriate z rows and cols
	zRows = xRows;
	zCols = yCols;
	
	//Dynamic Memory Allocation for input array z 
	z = new int *[xRows];
	for(int i = 0; i < xRows; i++)
		*(z + i) = new int[yCols];

	do {
		//Let user choose what to do with the matrices
		choice = menu();

		switch (choice) {
			case 1:
				if (addition(xRows, xCols, yRows, yCols)) {
					//Print matirx z
					cout << "\nMatrix one + Matrix two: " << endl;
					for(int i = 0; i < xRows; i++) {
						for(int j = 0; j < xCols; j++)
							cout << (*(*(x + i) + j) + *(*(y + i) + j)) << "\t";
						cout << endl;
					}
				}
				break;
			case 2:
				if (subtraction(xRows, xCols, yRows, yCols)) {
					//Print matirx z
					cout << "\nMatrix one - Matrix two: " << endl;
					for(int i = 0; i < xRows; i++) {
						for(int j = 0; j < xCols; j++)
							cout << (*(*(x + i) + j) - *(*(y + i) + j)) << "\t";
						cout << endl;
					}
				}
				break;
			case 3:
				if (multiplication(xRows, xCols, yRows, yCols)) {
					//Print matirx z
					cout << "\nMatrix one * Matrix two: " << endl;
					for(int i = 0; i < xRows; i++) {
						for(int j = 0; j < yCols; j++) {
							*(*(z + i) + j) = 0;	//Reset z[i][j] for next calculation
							for (int k = 0; k < yRows; k++)
								*(*(z + i) + j) += (*(*(x + i) + k) * *(*(y + k) + j));
							cout << *(*(z + i) + j) << "\t";
						}
					cout << endl;
					}
				}
				break;
			case 4:
				int ch;

				//Which matrix to transpose
				cout << "\nWhich Matrix: " << endl;
				cout << "1. Matrix one" << endl;
				cout << "2. Matrix two" << endl;
				cin >> ch;

				//Set up matrix z using matrix x
				if (ch == 1) {
					cout << "\nMatrix transpose: " << endl;
						for(int i = 0; i < xRows; i++)
							for(int j = 0; j < xCols; j++) {
								*(*(z + i) + j) = *(*(x + j) + i);
								*(*(z + j) + i) = *(*(x + i) + j);
							}
				}
				//Set up matrix z using matrix y
				else {
					cout << "\nMatrix transpose: " << endl;
						for(int i = 0; i < xRows; i++)
							for(int j = i; j < xCols; j++) {
								*(*(z + i) + j) = *(*(y + j) + i);
								*(*(z + j) + i) = *(*(y + i) + j);
							}
				}

				//Print matrix z
				for(int i = 0; i < xRows; i++) {
					for(int j = 0; j < xCols; j++)
						cout << *(*(z + i) + j) << "\t";
					cout << endl;
				}
				break;
			default:
				//End the program
				cout <<"Thank you!\n";
		}
	}
	while (choice != 5);

	system("pause");
	return 0;
}

int menu() {
	int choice;

	//Display menu and return choice
	cout << "\nSelect an option: " << endl;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Transpose of a Matrix" << endl;
	cout << "5. Exit program" << endl;
	cin >> choice;

	return choice;
}

//Check if addition is possible
bool addition(int xR, int xC, int yR, int yC) {
	if ((xR != yR) || (xC != yC)) {
		cout << "You cannot add a [" << xR << " x " << xC
			 <<  "] matrix with a [" << yR << " x " << yC
			 <<  "] matrix.\n";
		return false;
	}
	return true;
}

//Check if subtraction is possible
bool subtraction(int xR, int xC, int yR, int yC) {
	if ((xR != yR) || (xC != yC)) {
		cout << "You cannot subtraction a [" << xR << " x " << xC
			 <<  "] matrix with a [" << yR << " x " << yC
			 <<  "] matrix.\n";
		return false;
	}
	return true;
}

//Check if multiplication is possible
bool multiplication(int xR, int xC, int yR, int yC) {
	if ((xR != yC) || (xC != yR)) {
		cout << "You cannot multiplication a [" << xR << " x " << xC
			 <<  "] matrix with a [" << yR << " x " << yC
			 <<  "] matrix.\n";
		return false;
	}
	return true;
}