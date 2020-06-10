#pragma once
#include "EnigmaMachine.h"

class BEnigmaMachineManager
{
private:
	EnigmaMachine enigmaMachine1;
public:
	// Constructor
	BEnigmaMachineManager();

	// Print the status of the enimaMachine
	void printStatus();

	// Pring Debug
	void printDebug();

	// Encyt the string
	void encrytStr(string inputStr);

	// Print Menu and get user input
	void printMenu();
};

