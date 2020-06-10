#pragma once
#include "EnigmaMachine.h"

class BEnigmaMachineManager
{
private:
	EnigmaMachine enigmaMachine1;

	// User input check method
	bool isLetters(string inputStr);
public:
	// Constructor
	BEnigmaMachineManager();

	// Print the status of the enimaMachine
	void printStatus();

	// Pring Debug
	void printDebug();

	// Encyt the string
	string encrytStr(string inputStr);

	// Print Menu and get user input
	void printMenu();
};

