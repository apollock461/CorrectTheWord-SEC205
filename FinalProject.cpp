/*
 * FinalProject.cpp
 *
 *  Created on: Apr 26, 2019
 *      Author: Owner
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string getWord(string word); //function prototype
void getDirections(string direct);

int main() {

	string originalWord;
	string scrambleWord;
	string userInput;
	int score = 0;
	int numberOfWords = 16;
	char choice;
	string directions;
	string wordList[16];

	int arraysize = 16;
	string wordArray[arraysize];
	string current_char;
	int numCharacters = 0;
	int i = 0;

	ifstream file("dictionary.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			file >> wordArray[i];
			i++;
			numCharacters++;
		}

		for (int i = 0; i <= numCharacters; i++) {

			getDirections(directions);
			cout << "Would you like to Play?";
			cin >> choice;
			while (toupper(choice) == 'Y') {
				int randomizeWord = 0;
				randomizeWord = rand() % numCharacters + 1;
				cout << randomizeWord;
				for (int x = 1; x < randomizeWord; x++) {
					file >> originalWord;
					//cin >> wordList[16];
				}

				scrambleWord = getWord(originalWord);
				cout << "Correct the Following Word: " << scrambleWord << endl;
				//cout << originalWord;
				cin >> userInput;
				if (originalWord.compare(userInput) == 0) {
					cout << "Congratulations, your guess was correct!"
							<< wordArray[16] << endl;
					score += 1; //add one to the players score
				} else {
					cout << "Better luck next time." << endl;
					score += 0; //keep the score the player had, but do not add onto their current score
				}
				cout << "Your current score is: " << score << endl;
				cout << "Would you like to play again?" << endl;
				cin >> choice;

			}
			cout << "Thank you for playing.";
		}
		cout << wordArray[i] << endl;
	}

	system("pause");
}

string getWord(string word) { //scramble function definition
	string stringInput = word;
	for (int x = 0; x < stringInput.size(); x++) {
//		cout << stringInput.size();
		int tempWord = rand() % stringInput.size();
		char variable;
		variable = stringInput[tempWord];
		stringInput[tempWord] = stringInput[x];
		stringInput[x] = variable;
	}
	return stringInput;
}
void getDirections(string direct) {
	cout
			<< "Welcome to Correct the Word, the goal of this "
					"game is to guess the correct spelling of the word that is shown to you."
			<< endl;
	cout
			<< "If you guess the word correctly you will score "
					"one point, if you guess incorrectly you will score zero points. \n"
			<< endl;
}
