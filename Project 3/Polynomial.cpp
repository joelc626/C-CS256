//Joel Castro
//CS 256
//Project 3 Task 1: Polynomial

//This program asks the user for two polynomials and performs
//operations with them.

#include <iostream>
#include <cmath>

#include <iostream>

using namespace std;
int displayMenu();

class Term{
	private:
		float coefficient;
		int exponent;
		friend class Polynomial;
	public:
		Term();
		Term(float coefficient_arg,int exponent_arg);
		void setvalue(int exponent_arg);
		void setvalue(float coefficient_arg,int exponent_arg);
		void printterm();

};

Term::Term() {
	 coefficient = 0;
	 exponent = 0;
}

Term::Term (float coefficient_arg, int exponent_arg) {
	 coefficient = coefficient_arg;
	 exponent=exponent_arg;
}

void Term::setvalue (int exponent_arg) {
	cout << "Enter the coefficient for x^" << exponent_arg << ": ";
	cin >> coefficient;
	exponent = exponent_arg;
}

void Term::setvalue (float coefficient_arg, int exponent_arg) {
	coefficient = coefficient_arg;
	exponent = exponent_arg;
}

void Term::printterm() {
	//if its x^0, then display the coef
	if (exponent == 0)
		cout << coefficient;
	//if its x^1, then display the coef and "x"
	else if (exponent == 1)
		cout << coefficient << "x";
	//display the rest of the terms with "x^" + correct exponent
	else
		cout << coefficient << "x^" << exponent;
}

class Polynomial {
	private:
		int degree;
		Term *termArr;
	public:
		Polynomial();
		void setvalue();
		void printpolynomial();

		Polynomial operator+(const Polynomial &);
		Polynomial operator-(const Polynomial &);
		Polynomial operator*(const Polynomial &);
};

Polynomial::Polynomial() {
	degree = 0;
	Term *tempArr = new Term[degree + 1];
	Term zero;
	tempArr[0] = zero;
	termArr = tempArr;
}

void Polynomial::setvalue() {
	cout << "Enter the number of the highest exponent in the polynomial: ";
	cin >> degree;

	Term *tempArr = new Term[degree+1];
	for (int i = 0; i <= degree; i++)
		tempArr[i].setvalue(i);
	termArr = tempArr;
}

void Polynomial::printpolynomial() {
	termArr[degree].printterm();
	for (int i = degree - 1; i != -1; i--) {
		if (termArr[i].coefficient > 0) {
			cout << " + ";
			termArr[i].printterm();
			cout << " ";
		}
		if (termArr[i].coefficient < 0)  {
			cout << " ";
			termArr[i].printterm();
			cout<<" ";
		}
	}
}

Polynomial Polynomial::operator+(const Polynomial &arg) {
	Polynomial temp;
	float coefficient_temp;
	int lower_degree;

	if (degree > arg.degree) {
		temp.degree = degree;
		lower_degree = arg.degree;
	}
	else {
		temp.degree = arg.degree;
		lower_degree = degree;
	}

	Term *tempArr=new Term[temp.degree + 1];

	for (int i = 0; i <= lower_degree; i++) {
		coefficient_temp = termArr[i].coefficient + arg.termArr[i].coefficient;
		tempArr[i].setvalue(coefficient_temp, i);
	}

	for (int i = lower_degree+1; i <= temp.degree; i++) {
		if(degree > arg.degree) {
			coefficient_temp = termArr[i].coefficient;
			tempArr[i].setvalue(coefficient_temp, i);
		}
		else {
			coefficient_temp = arg.termArr[i].coefficient;
			tempArr[i].setvalue(coefficient_temp, i);
		}
	}
	 temp.termArr = tempArr;

	 return temp;
 }

Polynomial Polynomial:: operator-(const Polynomial &arg){
	Polynomial temp;
	float coefficient_temp;
	int lower_degree;

	if (degree > arg.degree) {
		temp.degree = degree;
		lower_degree = arg.degree;
	}
	else {
		temp.degree = arg.degree;
		lower_degree=degree;
	}

	Term *tempArr=new Term[temp.degree + 1];

	for (int i = 0; i <= lower_degree; i++) {
		coefficient_temp=termArr[i].coefficient - arg.termArr[i].coefficient;
		tempArr[i].setvalue(coefficient_temp, i);
	}

	for (int i = lower_degree + 1; i <= temp.degree; i++) {
		if(degree > arg.degree) {
			coefficient_temp=termArr[i].coefficient;
			tempArr[i].setvalue(coefficient_temp, i);
		}
		else {
			coefficient_temp=arg.termArr[i].coefficient;
			tempArr[i].setvalue(coefficient_temp, i);
		}
	}

	temp.termArr = tempArr;
	return temp;
}

/*
Polynomial Polynomial::operator*(const Polynomial &arg) {
	//TO COMPLICATED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
*/

 int main() {
	 int choice;

	cout << "First Polynomial:\n";
	Polynomial poly1;
	poly1.setvalue();
	cout << "\nSecond Polynomial:\n";
	Polynomial poly2;
	poly2.setvalue();

	do {
		cout << "\n1st polynomial: ";
		poly1.printpolynomial();
		cout << "\n2nd polynomial: ";
		poly2.printpolynomial();
		cout << "\n\n";

		choice = displayMenu();

		switch (choice) {
			case 1: {
				Polynomial add;
				add = poly1 + poly2;
				cout << "\nPolynomial 1 plus Polynomial 2 is: ";
				add.printpolynomial();
				cout << "\n\n";
				break;
				}
			case 2: {
				Polynomial minus;
				int pick;

				cout << "\n1. Polynomial 1 minus Polynomial 2\n";
				cout << "2. Polynomial 2 minus Polynomial 1\n";
				cin >> pick;
				if (pick == 1) {
					cout << "\nPolynomial 1 minus Polynomial 2 is: ";
					minus = poly1 - poly2;
				}
				else {
					cout << "\nPolynomial 2 minus Polynomial 1 is: ";
					minus = poly2 - poly1;
				}
				
				minus.printpolynomial();
				cout << "\n\n";
				break;
				}
			case 3: {
				cout << "\n\n*Dont have this one professor, sorry =(\n\n";
				/*
				Polynomial multiply;
				multiply = poly1 * poly2;
				cout<<"Polynomial 1 multiply Polynomial 2 is: ";
				multiply.printpolynomial();
				cout << "\n\n";
				*/
				break;
				}
			case 4: {
				int pick;

				cout << "\n1. Assign Polynomial 1\n";
				cout << "2. Assign Polynomial 2\n";
				cin >> pick;
				if (pick == 1) {
					cout << "\nAssign Polynomial 1\n ";
					poly1.setvalue();
				}
				else {
					cout << "\nAssign Polynomial 2\n ";
					poly2.setvalue();
				}
				break;
				}
			default: {
				break;
				}
		}
	}
	while (choice !=5);


 cout<<"Press enter to exit"<<endl;
 getchar();getchar();
 return 0;
 }
 
int displayMenu() {
	int choice;
	do {
		cout << "Choose an option :" << endl;
		cout << "(1) Addition\n";
		cout << "(2) Subtraction\n";
		cout << "(3) Multiplication\n";
		cout << "(4) Assignment\n";
		cout << "(5) Exit\n";
		cin >> choice;

		if (choice < 1 || choice > 5) {
			cout << "\nERROR\n!";
			cout<<"Enter a number between 1 and 5\n";
		}
	}
	while (choice < 1 || choice > 5);

	return choice ;
}