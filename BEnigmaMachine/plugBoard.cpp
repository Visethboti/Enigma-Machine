#include "pch.h"
#include "plugBoard.h"


// Constructor
plugBoard::plugBoard()
{
	left = "##########"; // 10 char
	right = "##########"; //10 char
	pairCounter = 0;
}

// Get Methods
string plugBoard::getLeft() {
	return left;
}

string plugBoard::getRight() {
	return right;
}

// Set Plugboard Method
void plugBoard::setPair(string inputPair) {
	if (pairCounter > 10)
		return;

	// Separate each of the input chars of the string inputPair into left and right.
	left[pairCounter] = inputPair[0];
	right[pairCounter] = inputPair[1];

	// Increment pairCounter by 1 after each setPair is used
	pairCounter++;
}

// Reset the plugboard (reset/delete all existing pairs)
void plugBoard::resetPair() {
	left = "##########";
	right = "##########";
	pairCounter = 0;
}

char plugBoard::crossPlugBoard(char inputChar) {
	char result;

	if (left.find(inputChar) != string::npos) {
		result = right.at(left.find(inputChar));
	}
	else if (right.find(inputChar) != string::npos) {
		result = left.at(right.find(inputChar));
	}
	else {
		result = inputChar;
	}

	return result;
}