//Joel Castro
//CS 256
//Project 3 Task 2: Tic-Tac-Toe Game

//This program lets two users play the classic game, Tic-Tac-Toe.

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class Tic_Tac_Toe {
	private:
		char board[3][3];
	public:
		Tic_Tac_Toe();
		void storing(int,int,char);
		void display();
		char winner();
};

Tic_Tac_Toe::Tic_Tac_Toe() {
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			board[i][j]='*';
}

void Tic_Tac_Toe::storing(int rw, int col, char ch) {
	board[rw][col] = ch;
}

void Tic_Tac_Toe::display() {
	for(int r = 0; r < 3; r++) {
		for(int c = 0; c < 3; c++) {
			if (c == 0)
				cout << "\t" << board[r][c] << "|";
			else if (c == 1)
				cout << board[r][c] << "|";
			else
				cout << board[r][c];
		}
		if (r == 2)
			cout << endl;
		else
			cout << endl << "\t-----" << endl;
	}
}

char Tic_Tac_Toe::winner() {
	for(int i = 0; i < 3; i++) {
		//return horizontal winner
		if(board[i][0] != '*' && board[i][0] == board[i][1]
				&& board[i][1] == board[i][2])
			return board[i][0];	

		//return vertical winner
		else if (board[0][i] != '*' && board[0][i] == board [1][i]
				&& board[1][i] == board[2][i]) 
			return board [0][i];
	}

	//return backslash diagonal winner
	if (board[0][0] != '*' && board[0][0] == board[1][1]
			&& board[1][1] == board[2][2])
		return board[0][0];	

	//return forwardslash diagonal winner
	else if (board[0][2] != '*' && board[0][2] == board[1][1]
			&& board[1][1] == board[2][0])
		return board[0][2];		
	
	//return no winner
	return 'n';
}

int main() {
	string pla1, pla2;
	char again;
	
	do {
		system("CLS");
		Tic_Tac_Toe ttt;

		cout << "First player, enter your name: ";
		cin >> pla1;
		cout << "Second player, enter your name: ";
		cin >> pla2;

		cout << endl;
	
		//display the contents of the board
		ttt.display();

		for (int rounds = 0; rounds < 5; rounds++) {
			int x, y, w, z;
			char ch;

			cout << endl << pla1 << ", select a location on the board with an '*' symbol.\n"
				<< "Enter a row (1-3) and a colomn (1-3) seperate by a space.\n"
				<< "Make your move: ";
			cin >> x >> y;
			ch = 'X';
			ttt.storing(--x, --y, ch);
			cout <<endl;

			//display the contents of the board
			ttt.display();

			//Only check for winner after enough rounds
			if (rounds > 1)
				if (ttt.winner() ==  'X') {
					cout << pla1 << ", wins!";
					break;
				}

			//Tie!
			if (rounds == 4) {
				cout << endl << "Tie!";
				break;
			}

			cout << endl << pla2 << ", select a location on the board with an '*' symbol.\n"
				<< "Enter a row (1-3) and a colomn (1-3) seperate by a space.\n"
				<< "Make your move: ";
			cin >> x >> y;
			ch = 'O';
			ttt.storing(--x, --y, ch);
			cout <<endl;

			//display the contents of the board
			ttt.display();

			//Only check for winner after enough rounds
			if (rounds > 1)
				if (ttt.winner() ==  'O') {
					cout << pla2 << ", wins!";
					break;
				}
		}
		cout << "\n\nPlay again? (y or n): ";
		cin >> again;
	}
	while (again == 'y');

	cout << endl;
	system("pause");
	return 0;
}