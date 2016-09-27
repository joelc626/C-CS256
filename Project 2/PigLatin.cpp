//Joel Castro
//CS 256
//Project 2 Task 1: Pig Latin

//This program asks the user for a sentence and converts it to Pig Latin.

#include<iostream>
#include <string>
using namespace std;

void pigLatin(string engWord) {
	string pigWord;
	int wordLen = engWord.length( );

	//convert to pig latin
	pigWord = engWord.substr(1, wordLen) + engWord.substr(0, 1) + "ay " ;

	//Convert to upper case
	for(int i = 0; i < pigWord.length();i++)
		pigWord[i] = toupper(pigWord[i]);

	//print pig latin word
	cout << pigWord;
	}

int main()
{
	string engWord, sentence;
    bool finished = false;
    int position;

	//Ask for a sentence
	cout << "Welcome to Pig Latin translator!\n";
	cout << "Enter a sentence:\n";
	getline(cin, sentence);

	//while all words are not finished continue the loop
	while (!finished) {
		//look for spaces
		position = sentence.find(" ");

		//if no spaces left then set finishded true
        if (position == -1) {
			finished = true;

			//set position to remaining length of phrase
            position = sentence.length( );
        }
		//seperate word
		engWord = sentence.substr(0, position);

		//call function to translate word that has character(s)
		if (engWord != "")
			pigLatin(engWord);

        //delete processed word if not finished
        if (!finished)
			sentence = sentence.substr(position + 1, sentence.length( ) - position + 1);
	}

	cout << endl;
	system("pause");
	return 0;
}