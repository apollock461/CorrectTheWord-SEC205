//Created By: Mia Harkins, Ashley Pollock
//Date: May 14, 2019 

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//function definitions
void getDirections(string direct) {
	cout
		<< "Welcome to Correct the Word, the goal of this game is to guess the correct spelling of the word that is shown to you."
		<< endl;
	cout
		<< "If you guess the word correctly you will score one point, if you guess incorrectly you will score zero points. \n"
		<< endl;
}
string scramble(string word) {
	string str = word;
	for (int i = 0; i < str.size(); i++) {
		int temp = rand() % str.size();
		char t;
		t = str[temp];
		str[temp] = str[i];
		 str[i] = t;
	}
	return str;
}

int main() {
	srand(time(0));
	int numberGames = 0;
	int totalGuesses = 0;
	int numberOfWords = 50;
	int score = 0;
	string directions;
	string originalWord;
	string scrambledWord;
	char choice;

	ifstream inFile("dictionary.txt");
	getDirections(directions);

	cout << "Would you like to Play?";
	cin >> choice;

	while (toupper(choice) == 'Y') {
		// variable to store current guess
		int numberGuess = 0;
		string userInput;
		// randomly select a word from file
		int wordNo = rand() % numberOfWords + 1;
		for (int i = 1; i < wordNo; i++) {
			while(m,n )
			inFile >> originalWord;
		}
		// get the scrambled word
		scrambledWord = scramble(originalWord);
		// print the scrambled word
		cout << "Correct the Following Word: " << scrambledWord << endl;
		// loop to input guesses for current word
		while (toupper(choice) == 'Y') {
			// prompt the user for a guess
			cout << "Enter your guess: ";
			cin >> userInput;

			// check whether the guess is true
			if (originalWord.compare(userInput) == 0) {
				numberGuess++;
				score += 1;
				cout << "Congratulations, your guess was correct! " << endl;
				break;
			} else {
				cout << "Please try again." << endl;
				numberGuess++;
				score += 0;
			}
			totalGuesses++;
		}
		cout << "Your score is: " << score << endl;
		char choiceToo;
		cout << "Do you wish to play again?";
		cin >> choiceToo;
		if (toupper(choiceToo) == 'Y') {
			if(eof()){

			}
			numberGames++;
			continue;
		} else
			break;
		// print the final outputs
	}
	cout << "Thank you for playing." << endl;
}
