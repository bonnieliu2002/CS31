/* Name: Bonnie Liu
   ID: 005300989
   Class: CS 31
   Discussion: 1F
   Date: 10/31/2019
   Project 3: Nefarious Plots
*/

#include "grid.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

const int HORIZ = 0;
const int VERT = 1;

const int FG = 0;
const int BG = 1;

bool plotLine(int r, int c, int distance, int dir, char plotChar, int fgbg);
int performCommands(string commandString, char& plotChar, int& mode, int& badPos);
bool testHorVstep(string cmd, int& k);
bool testForBstep(string cmd, int& k);
bool processHstep(string cmd, int& k, int& r, int& c, char ch, int mode);
bool processVstep(string cmd, int& k, int& r, int& c, char ch, int mode);
int findDistance(string num);

int main()
{
	setSize(20, 30);
	char currentChar = '*';
	int currentMode = FG;
	for (;;)
	{
		cout << "Enter a command string: ";
		string cmd;
		getline(cin, cmd);
		if (cmd == "")
			break;
		int position;
		int status = performCommands(cmd, currentChar, currentMode, position);
		switch (status)
		{
		case 0:
			draw();
			break;
		case 1:
			cout << "Syntax error at position " << position + 1 << endl;
			break;
		case 2:
			cout << "Cannot perform command at position " << position + 1 << endl;
			break;
		default:
			// It should be impossible to get here.
			cerr << "performCommands returned " << status << "!" << endl;
		}
	}
}

int performCommands(string commandString, char& plotChar, int& mode, int& badPos) {
	int k = 0;
	int row = 1;
	int col = 1;
	// parses commandString
	while (k != commandString.size()) {
		if (commandString[k] == 'H' || commandString[k] == 'h' || commandString[k] == 'V' || commandString[k] == 'v') {
			if (!testHorVstep(commandString, k)) {
				badPos = k;
				return 1;
			}
		}
		else if (commandString[k] == 'F' || commandString[k] == 'f' || commandString[k] == 'B' || commandString[k] == 'b') {
			if (!testForBstep(commandString, k)) {
				badPos = k;
				return 1;
			}
		}
		else if (commandString[k] == 'C' || commandString[k] == 'c') {
			k++;
		}
		else {
			badPos = k;
			return 1;
		}
	}
	// performs command if everything is okay
	k = 0;
	while (k != commandString.size()) {
		if (commandString[k] == 'H' || commandString[k] == 'h') {
			if (!processHstep(commandString, k, row, col, plotChar, mode)) {
				badPos = k;
				return 2;
			}
		}
		else if (commandString[k] == 'V' || commandString[k] == 'v') {
			if (!processVstep(commandString, k, row, col, plotChar, mode)) {
				badPos = k;
				return 2;
			}
		}
		else if (commandString[k] == 'F' || commandString[k] == 'f') {
			mode = FG;
			plotChar = commandString[k+1];
			k=k+2;
		}
		else if (commandString[k] == 'B' || commandString[k] == 'b') {
			mode = BG;
			plotChar = commandString[k+1];
			k=k+2;
		}
		else if (commandString[k] == 'C' || commandString[k] == 'c') {
			clearGrid();
			row = 1;
			col = 1;
			plotChar = '*';
			mode = FG;
			k++;
		}
	}
	return 0;
}

bool testHorVstep(string cmd, int& k) {
	k++;
	string distance = "";
	do {
		distance += cmd[k];
		k++;
	} while (((distance[0] == '-' && distance.size() < 3) || (isdigit(distance[0]) && distance.size() < 2)) && isdigit(cmd[k]));
	if ((distance[0] != '-' && !isdigit(distance[0])) || (distance[0] == '-' && distance.size() == 1)) {
		k = k - distance.size();
		return false; // syntax error
	}
	if ((distance[0] == '-' && distance.size() > 3) || (isdigit(distance[0]) && distance.size() > 2))
		return false; // syntax error
	return true;
}

bool testForBstep(string cmd, int& k) {
	k++;
	if (!isprint(cmd[k]) || k >= cmd.size()) {
		return false;
	}
	k++;
	return true;
}

bool processHstep(string cmd, int& k, int& r, int& c, char ch, int mode) {
	k++;
	string distance = "";
	do {
		distance += cmd[k];
		k++;
	} while (((distance[0] == '-' && distance.size() < 3) || (isdigit(distance[0]) && distance.size() < 2)) && isdigit(cmd[k]));
	// We test to see if the program tries to plot off the grid.
	// distance is negative
	if (distance[0] == '-') {
		if (plotLine(r, c, -1 * findDistance(distance.substr(1, distance.size() - 1)), HORIZ, ch, mode)) {
			c -= findDistance(distance.substr(1, distance.size() - 1));
		}
		else {
			k = k - distance.size() - 1;
			return false;
		}
	}
	// distance is positive
	else {
		if (plotLine(r, c, findDistance(distance), HORIZ, ch, mode)) {
			c += findDistance(distance);
		}
		else {
			k = k - distance.size() - 1;
			return false;
		}
	}
	return true;
}

bool processVstep(string cmd, int& k, int& r, int& c, char ch, int mode) {
	k++;
	string distance = "";
	do {
		distance += cmd[k];
		k++;
	} while (((distance[0] == '-' && distance.size() < 3) || (isdigit(distance[0]) && distance.size() < 2)) && isdigit(cmd[k]));
	// We test to see if the program tries to plot off the grid.
	// distance is negative
	if (distance[0] == '-') {
		if (plotLine(r, c, -1 * findDistance(distance.substr(1, distance.size() - 1)), VERT, ch, mode)) {
			r -= findDistance(distance.substr(1, distance.size() - 1));
		}
		else {
			k = k - distance.size() - 1;
			return false;
		}
	}
	// distance is positive
	else {
		if (plotLine(r, c, findDistance(distance), VERT, ch, mode)) {
			r += findDistance(distance);
		}
		else {
			k = k - distance.size() - 1;
			return false;
		}
	}
	return true;
}

bool plotLine(int r, int c, int distance, int dir, char plotChar, int fgbg) {
	// checks if parameters dir, fgbg, and plotChar are valid
	if ((dir != HORIZ && dir != VERT) || (fgbg != FG && fgbg != BG) || (!isprint(plotChar)))
		return false;
	// checks horizontal cases to determine whether line will go off grid
	if (dir == HORIZ) {
		if (distance > 0 && (c + distance > getCols()))
			return false;
		else if (distance < 0 && c + distance < 1)
			return false;
		// won't go off grid, so now we set characters to what we want
		// horizontal and positive distance
	}
	// checks vertical cases to determine whether line will go off grid
	else {
		if (distance > 0 && (r + distance > getRows()))
			return false;
		else if (distance < 0 && (r + distance < 1))
			return false;
		// won't go off grid, so now we set characters to what we want
	}
	// after checking all conditions, program starts plotting points if applicable
	// distance is 0
	if (distance == 0) {
		if (fgbg == 0 || getChar(r, c) == ' ')
			setChar(r, c, plotChar);
	}
	// distance is positive and direction is horizontal
	else if (distance > 0 && dir == HORIZ) {
		for (int i = 0; i <= distance; i++)
			if (fgbg == 0 || getChar(r, c + i) == ' ')
				setChar(r, c + i, plotChar);
	}
	// distance is negative and direction is horizontal
	else if (distance < 0 && dir == HORIZ) {
		for (int i = distance; i <= 0; i++) {
			if (fgbg == 0 || getChar(r, c + i) == ' ')
				setChar(r, c + i, plotChar);
		}
	}
	// distance is positive and direction is vertical
	else if (distance > 0 && dir == VERT) {
		for (int i = 0; i <= distance; i++) {
			if (fgbg == 0 || getChar(r + i, c) == ' ')
				setChar(r + i, c, plotChar);
		}
	}
	// distance is negative and direction is vertical
	else {
		for (int i = distance; i <= 0; i++) {
			if (fgbg == 0 || getChar(r + i, c) == ' ')
				setChar(r + i, c, plotChar);
		}
	}
	return true;
}

// converts a number given in the form of a string into an integer
int findDistance(string num) {
	int x = 0;
	for (int i = 0; i < num.size(); i++) {
		char ch = '0';
		int n = ch;
		int m = num[i];
		x += m - n;
		if (i != num.size() - 1) {
			x *= 10;
		}
	}
	return x;
}