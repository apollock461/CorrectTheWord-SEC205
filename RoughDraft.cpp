/*
 * RoughDraft.cpp
 *
 *  Created on: Apr 26, 2019
 *      Author: Owner
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


void scrambleWord(string word); //void function definition

int main(){

//	ifstream file;
//	file.open("dictionary.txt");
	string word;
	string scrambleWord;
	string userInput;
	int score = 0;
	char choice;

	cout << "Would you like to Play?";
	cin >> choice;

	while (toupper(choice) == 'Y'){
		cout << "Correct the Following Word: " << scrambleWord << endl;
		cin >> userInput;
		if(userInput == scrambleWord){
				cout << "Congratulations, your guess was correct!" << endl;
				score += 1; //add one to the players score
			}
		else{
				cout << "Better luck next time." << endl;
				score += 0; //keep the score the player had, but do not add onto their current score
			}
	cout << "Your current score is: " << score << endl;
	cout << "Would you like to play again?" << endl;
		cin >> choice;
	}
	cout << "Thank you for playing.";
}

void scrambleWord(string word) {
	std::string dictionary = "dictionary.txt";
	ifstream file;
	file.open("dictionary.txt");

	char character;
	int word1, word2;
	word = file.get();

	if (word.length() <= 50){
		word1 = rand() % (word.length() - 1) + 1;
		word2 = word1;
	}
/*
	while (word2 == word1){
		word2 = rand() % (word.length() - 1) + 1;
	}
*/
	character = word[word1];
	word[word1] = word[word2];
	word[word2] = character;
	//	scrambleWord = word;
}



