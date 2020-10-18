/* Name: Bonnie Liu
   Student ID: 005300989
   Class: CS 31 Discussion 1F
   Project 5: Flower Power
   Due Date: 11/18/2019
   */

#pragma warning(disable:6262)
#define _CRT_SECURE_NO_DEPRECATE
#include "utilities.h"
#include <iostream>
#include <cstring>
using namespace std;

// declare constant variables
const char WORDFILENAME[] = "C:/Users/bonni/Desktop/CS31/mywordfile.txt";
const int MAXWORDS = 10000;

// declare prototypes of functions
int playOneRound(const char words[][MAXWORDLEN+1], int nWords, int wordnum);
void helper(const char mysteryWord[], char trialWord[]);

int main()
{
	// fill wordList array with words
	char wordList[MAXWORDS][MAXWORDLEN + 1];
	int nWords = getWords(wordList, MAXWORDS, WORDFILENAME);
	// if there are no words in text file, terminate program
	if (nWords < 1) {
		cout << "No words were loaded, so I can't play the game." << endl;
		return -1;
	}
	// prompt user for number of rounds
	cout << "How many rounds do you want to play? ";
	int numRounds;
	cin >> numRounds;
	cin.ignore(10000, '\n');
	// check if number of rounds user inputted is positive
	if (numRounds <= 0) {
		cout << "The number of rounds must be positive." << endl;
		return -1;
	}
	int totalScore = 0;
	double avgScore;
	int maxScore;
	int minScore;
	// repeat for numRounds times
	for (int i = 0; i < numRounds; i++) {
		cout << endl;
		cout << "Round " << i + 1 << endl;
		// randomly select index of mystery word
		int indexOfMysteryWord = randInt(0, nWords - 1);
		// set mysteryWord to appropriate word from list based on randomly selected index
		char mysteryWord[100] = {};
		strcat(mysteryWord, wordList[indexOfMysteryWord]);
		// tell user how many letters long mystery word is
		cout << "The mystery word is " << strlen(mysteryWord) << " letters long." << endl;
		// play one round and get score
		int oneRoundScore = playOneRound(wordList, nWords, indexOfMysteryWord);
		cout << "You got it in " << oneRoundScore;
		if (oneRoundScore == 1) {
			cout << " try." << endl;
		}
		else {
			cout << " tries." << endl;
		}
		totalScore += oneRoundScore;
		// set initial score
		if (i == 0) {
			maxScore = oneRoundScore;
			minScore = oneRoundScore;
		}
		// if current score is greater than maximum score, set maximum score to current score
		if (oneRoundScore > maxScore) {
			maxScore = oneRoundScore;
		}
		// if current score is less than mimimum score, set minimum score to current score
		if (oneRoundScore < minScore) {
			minScore = oneRoundScore;
		}
		// find and print statistics (average, minimum, maximum)
		avgScore = static_cast<double>(totalScore) / (i + 1);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Average: " << avgScore << ", minimum: " << minScore << ", maximum: " << maxScore << endl;
	}
}

int playOneRound(const char words[][MAXWORDLEN+1], int nWords, int wordnum) {
	// if there is a problem with parameters, return -1
	if (nWords <= 0 || wordnum < 0 || wordnum >= nWords) {
		return -1;
	}
	char trialWord[101] = "";
	int score = 0;
	// WHILE LOOP SHOULD GO HERE (CONDITION: TRIALWORD == MYSTERYWORD)
	while (strcmp(trialWord, words[wordnum]) != 0) {
		// prompt user for trial word
		cout << "Trial word: ";
		cin.getline(trialWord, 101);
		// traverse trial word, and if any letter is not a lower-case letter, trial word is not valid
		bool trialWordIsValid = true;
		for (int i = 0; i < strlen(trialWord); i++) {
			if (!islower(trialWord[i])) {
				trialWordIsValid = false;
			}
		}
		// if trial word is too short or too long or if trial word contains char that is not lower-case, print error message
		if (strlen(trialWord) < MINWORDLEN || strlen(trialWord) > MAXWORDLEN || !trialWordIsValid) {
			cout << "Your trial word must be a word of 4 to 6 lower case letters." << endl;
		}
		else {
			// make sure trial word appears in our text file
			trialWordIsValid = false;
			for (int i = 0; i < nWords; i++) {
				if (strcmp(trialWord, words[i]) == 0) {
					trialWordIsValid = true;
				}
			}
			// if trial word does not appear in text file, print error message
			if (!trialWordIsValid) {
				cout << "I don't know that word." << endl;
			}
			// trial word is valid!
			else {
				helper(words[wordnum], trialWord);
				score++;
			}
		}
	}
	return score;
}

void helper(const char mysteryWord[], char trialWord[]) {
	// if trial word and mystery word are the same, return to playOneRound function
	if (strcmp(trialWord, mysteryWord) == 0) {
		return;
	}
	// find length of the words
	int lengthOfMysteryWord = 0;
	for (int i = 0; mysteryWord[i] != '\0'; i++) {
		lengthOfMysteryWord++;
	}
	int lengthOfTrialWord = 0;
	for (int i = 0; trialWord[i] != '\0'; i++) {
		lengthOfTrialWord++;
	}
	// determine minimum possible length of words to prevent out-of-bounds error later
	int minLength;
	if (lengthOfMysteryWord > lengthOfTrialWord) {
		minLength = lengthOfTrialWord;
	}
	else {
		minLength = lengthOfMysteryWord;
	}
	// make copies of trialWord and mysteryWord
	char copyOfTrialWord[100];
	strcpy(copyOfTrialWord, trialWord);
	char copyOfMysteryWord[100];
	strcpy(copyOfMysteryWord, mysteryWord);
	// find number of flowers
	int nFlowers = 0;
	for (int i = 0; i < minLength; i++) {
		if (mysteryWord[i] == trialWord[i]) {
			copyOfTrialWord[i] = '-';
			copyOfMysteryWord[i] = '*';
			nFlowers++;
		}
	}
	// find number of bees
	int nBees = 0;
	for (int i = 0; i < lengthOfMysteryWord; i++) {
		for (int j = 0; j < lengthOfTrialWord; j++) {
			if (copyOfTrialWord[j] == copyOfMysteryWord[i]) {
				nBees++;
				copyOfTrialWord[j] = '-';
				copyOfMysteryWord[i] = '*';
			}
		}
	}
	// print number of flowers and bees
	cout << "Flowers: " << nFlowers << ", Bees: " << nBees << endl;
}