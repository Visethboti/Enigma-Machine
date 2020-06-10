#pragma once

#include <string>
using namespace std;

class Rotor {
private:
	// rotor status
	int rotorNumber, rotorPosition;

	// rotorLeft is the input, right is the output (only the rotorRight is rotate)
	string rotorLeft, rotorRight;

public:
	// Constructor
	Rotor();

	// Methods for set and get Rotor Number and, get Rotor Position
	int getRotorNum();
	void setRotorNum(int rotorNum, string rotorIn);
	int getRotorPos();
	

	// Get Rotor Left and Right
	string getRotorLeft();
	string getRotorRight();

	// Set Rotor position and rotate it into position
	void setRotorPos(int posIn);

	// Rotate Methods
	void rotate();
	void resetPos();

	// Input Method (output the char accordingly)
	char inputChar(char input);

	// Reverse Input (Come from Right to Left)
	char reverseInputChar(char input);
};