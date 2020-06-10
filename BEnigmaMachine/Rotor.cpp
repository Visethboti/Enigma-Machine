#include "pch.h"
#include "Rotor.h"

//Constructor
Rotor::Rotor()
{
	rotorLeft = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	rotorRight = "??????????????????????????";
	rotorPosition = -1;
	rotorNumber = -1;
}


// Methods get and set
int Rotor::getRotorNum() {
	return rotorNumber;
}

void Rotor::setRotorNum(int rotorNum, string rotorIn) {
	rotorNumber = rotorNum;
	rotorRight = rotorIn;
}

int Rotor::getRotorPos() {
	return rotorPosition;
}

string Rotor::getRotorLeft() {
	return rotorLeft;
}

string Rotor::getRotorRight() {
	return rotorRight;
}

void Rotor::setRotorPos(int posIn) {
	rotorPosition = posIn;

	// Rotate the rotor into position
	for (int i = 1; i < rotorPosition; i++) {
		// Roate the rotor
		rotorRight = rotorRight.at(25) + rotorRight;
		rotorRight.pop_back();
	}
}


// Rotate Method and increment position
void Rotor::rotate() {
	rotorRight = rotorRight.at(25) + rotorRight;
	rotorRight.pop_back();
	rotorPosition++;
}

void Rotor::resetPos() {
	rotorPosition = 1;
}


// Input Method, input a char and output the char accordingly then rotate by one position.
char Rotor::inputChar(char input) {
	// Find the index of where the input char at in rotorLeft and output the char at that index in rotorRight
	return rotorRight.at(rotorLeft.find(input));
}


// Reverse Input Method, getting char from the left of the rotor.
char Rotor::reverseInputChar(char input) {
	// Find the index of where the inter char at in rotorRight and output the char at that index in rotorLeft
	return rotorLeft.at(rotorRight.find(input));
}